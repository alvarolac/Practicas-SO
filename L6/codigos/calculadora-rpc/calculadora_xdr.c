/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"

bool_t
xdr_terminos (XDR *xdrs, terminos *objp)
{
	register int32_t *buf;

	 if (!xdr_float (xdrs, &objp->t1))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->t2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_t_potencia (XDR *xdrs, t_potencia *objp)
{
	register int32_t *buf;

	 if (!xdr_float (xdrs, &objp->t1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->exp))
		 return FALSE;
	return TRUE;
}
