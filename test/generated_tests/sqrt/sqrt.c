#include <stdlib.h>
#include "sqrt.h"

/* ----------------------- BEGIN GENERATED CODE --------------------------- */
qc_socp * qc_sqrt2socp(const sqrt_params * params, const sqrt_dims * dims)
{
    /*
     * maps 'params' into the C socp data type
     * 'params' ought to contain:
     */

    /* all local variables */
    long i;  /* loop index */
    long *q_ptr;
    long *A_row_ptr, *A_col_ptr;
    long *G_row_ptr, *G_col_ptr;
    double *A_data_ptr, *G_data_ptr;
    long nnzA, nnzG;
    qc_matrix *G_csc, *A_csc;  /* possibly un-used */
    qc_matrix G_coo, A_coo;    /* possibly un-used */

    /* allocate socp data structure */
    qc_socp * data = (qc_socp *) calloc(1, sizeof(qc_socp));
    if (!data) return qc_socp_free(data);

    /* allocate problem dimensions */
    data->p = 0;
    data->m = 4;
    data->n = 2;

    /* allocate c vector */
    data->c = (double *) calloc(data->n, sizeof(double));
    if (!data->c) return qc_socp_free(data);

    /* allocate h vector */
    data->h = (double *) calloc(data->m, sizeof(double));
    if (!data->h) return qc_socp_free(data);

    /* allocate b vector */
    data->b = NULL;

    /* allocate G matrix */
    nnzG =  + 4;
    data->Gx = (double *) malloc(nnzG * sizeof(double));
    data->Gp = (long *) malloc(nnzG * sizeof(long));
    data->Gi = (long *) malloc(nnzG * sizeof(long));
    if ((!data->Gx) || (!data->Gp) || (!data->Gi)) return qc_socp_free(data);
    G_data_ptr = data->Gx;
    G_row_ptr = data->Gi;
    G_col_ptr = data->Gp;

    /* allocate A matrix */
    nnzA = 0;
    data->Ax = NULL;
    data->Ap = NULL;
    data->Ai = NULL;
    A_data_ptr = data->Ax;
    A_row_ptr = data->Ai;
    A_col_ptr = data->Ap;

    /* allocate the cone sizes */
    data->l = 1;
    data->nsoc = 1;
    data->q = (long *) malloc(data->nsoc * sizeof(long));
    if(!data->q) return qc_socp_free(data);

    /* initialize the cone */
    q_ptr = data->q;
    *q_ptr++ = 3;

    /* stuffing the objective vector */
    for(i = 0; i < 1; ++i) data->c[i + 0] = -1;

    /* for the constraint 0 + -1*x <= 0 */
    for(i = 0; i < 1; ++i) data->h[i + 0] = 0;
    *G_row_ptr++ = 0;
    *G_col_ptr++ = 1;
    *G_data_ptr++ = -1;

    /* for the SOC product constraint norm(1 + -1*x, 2.0*_t0) <= x + 1 */
    *G_row_ptr++ = 3;
    *G_col_ptr++ = 0;
    *G_data_ptr++ = -2.0;
    for(i = 0; i < 1; ++i) data->h[3 * i + 2] = 1;
    *G_row_ptr++ = 2;
    *G_col_ptr++ = 1;
    *G_data_ptr++ = 1;
    for(i = 0; i < 1; ++i) data->h[3 * i + 1] = 1;
    *G_row_ptr++ = 1;
    *G_col_ptr++ = 1;
    *G_data_ptr++ = -1;

    /* convert G and A ptrs into a qc_matrix */
    G_coo.m = data->m; G_coo.n = data->n; G_coo.nnz = nnzG;
    G_coo.i = data->Gi;
    G_coo.j = data->Gp;
    G_coo.v = data->Gx;

    /* convert the matrices to column compressed form */
    G_csc = qc_compress(&G_coo);
    if (!G_csc) return qc_socp_free(data);
    /* reassign into data, pointer now owned by data */
    data->Gi = G_csc->i;
    data->Gp = G_csc->j;
    data->Gx = G_csc->v;

    return data;
}

void qc_socp2sqrt(double * x, sqrt_vars * vars, const sqrt_dims * dims)
{
    /*
     * recovers the problem variables from the solver variable 'x'
     * assumes the variables struct is externally allocated
     * the user must keep track of the variable length;
     */
    vars->x = *(x + 1);
}
/* ------------------------ END GENERATED CODE ---------------------------- */
