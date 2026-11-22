// func rdmngr_db_generate_rd_idx @ 0061ad64 size=244

int rdmngr_db_generate_rd_idx(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0) {
    return -1;
  }
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  if (iVar1 + iVar2 <= param_1) {
    if (param_1 < 50000) {
      return -1;
    }
    iVar1 = apmngr_db_get_sensor_max();
    if (iVar1 + 50000 <= param_1) {
      return -1;
    }
  }
  iVar1 = -1;
  if ((0 < (int)param_2) && (param_2 <= DAT_007cc65c)) {
    if (49999 < param_1) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      param_1 = param_1 + -50000 + iVar1 + iVar2;
    }
    iVar1 = (param_2 - 1) + param_1 * DAT_007cc65c;
  }
  return iVar1;
}

