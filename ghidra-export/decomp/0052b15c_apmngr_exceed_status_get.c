// func apmngr_exceed_status_get @ 0052b15c size=68

bool apmngr_exceed_status_get(void)

{
  bool bVar1;
  int extraout_v1;
  
  bVar1 = false;
  if (g_apmngr_exceed_time != -1) {
    FUN_00407e70();
    bVar1 = extraout_v1 - g_apmngr_exceed_time < 0x3c;
  }
  return bVar1;
}

