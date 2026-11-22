// func _fail_sta_sc_handle @ 00667da0 size=40

void _fail_sta_sc_handle(int param_1)

{
  if ((fail_sta_hdl != (code *)0x0) && (param_1 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00667db8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*fail_sta_hdl)();
    return;
  }
  return;
}

