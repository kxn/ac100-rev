// func multi_link_status_get @ 00664298 size=188

undefined1 multi_link_status_get(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if (((int)param_1 < iVar1) ||
     ((uVar3 = 0, 49999 < param_1 &&
      ((iVar1 = apmngr_db_get_sensor_max(), (int)param_1 < iVar1 + 50000 ||
       (iVar1 = apmngr_db_get_sensor_max(), (int)param_1 < iVar1 + 50000)))))) {
    iVar1 = g_multi_link_array;
    if (param_1 < 50000) {
      uVar3 = *(undefined1 *)(g_multi_link_array + param_1);
    }
    else {
      iVar2 = apmngr_db_get_ap_max();
      uVar3 = *(undefined1 *)(iVar1 + (param_1 - 50000) + iVar2);
    }
  }
  return uVar3;
}

