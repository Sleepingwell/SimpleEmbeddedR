#include <R.h>
#include <Rinternals.h>
#include <R_ext/Parse.h>

char const* runRCode(char const* code) {
    SEXP e, tmp, rRes;
    char const *cResTmp;
    char *cRes;
    R_len_t i;
    int hasError;
    ParseStatus status;
    PROTECT(tmp = mkString(code));
    PROTECT(e = R_ParseVector(tmp, -1, &status, R_NilValue));
    if(status != PARSE_OK) {
        cResTmp = "Error in parsing code";
    } else {
        for(i=0; i<length(e); i++) {
            rRes = R_tryEval(VECTOR_ELT(e,i), R_GlobalEnv, &hasError);
            if(hasError) break;
        }
        if(hasError) {
            cResTmp = "Error occured when evaluating code";
        } else if(isString(rRes)) {
            cResTmp = CHAR(STRING_ELT(rRes,0));
        } else {
            cResTmp = "Non-string returned from R";
        }
    }
    cRes = (char*) malloc(sizeof(char) * (strlen(cResTmp) + 1));
    strcpy(cRes, cResTmp);
    UNPROTECT(2);
    return cRes;
}
