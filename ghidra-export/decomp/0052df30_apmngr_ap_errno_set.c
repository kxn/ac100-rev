// func apmngr_ap_errno_set @ 0052df30 size=168

undefined4 apmngr_ap_errno_set(ushort param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar3 = (uint)param_1;
  local_20 = 0;
  local_1c = 0;
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  if (((int)uVar3 < iVar1 + iVar2) ||
     ((uVar4 = 0xffffffff, 49999 < uVar3 &&
      (iVar1 = apmngr_db_get_sensor_max(), (int)uVar3 < iVar1 + 50000)))) {
    local_20 = CONCAT22(param_1,local_20._2_2_);
    uVar4 = 0xffffffff;
    local_1c = param_2;
    iVar1 = apmngr_db_sqlite_notify_msg(0xc,&local_20,8);
    if (iVar1 == 0) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

