// func cw_priv_chnl_scan_report_length @ 005add30 size=28

int cw_priv_chnl_scan_report_length(byte *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (byte *)0x0) {
    iVar1 = (uint)*param_1 * 9;
  }
  return iVar1;
}

