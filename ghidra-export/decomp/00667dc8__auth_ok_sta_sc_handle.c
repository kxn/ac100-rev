// func _auth_ok_sta_sc_handle @ 00667dc8 size=40

void _auth_ok_sta_sc_handle(int param_1)

{
  if ((auth_ok_sta_hdl != (code *)0x0) && (param_1 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00667de0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*auth_ok_sta_hdl)();
    return;
  }
  return;
}

