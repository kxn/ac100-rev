// func stats_db_ctl_rssi_update @ 0066c06c size=268

void stats_db_ctl_rssi_update(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  code *pcVar8;
  
  puVar6 = &rssi_interval_fun;
  puVar4 = &rssi_switch_fun;
  bVar1 = 0;
  uVar5 = 0x78;
  FUN_004082d0(l_stats_data,0xffffffff);
  for (iVar7 = 0; iVar7 < rssi_reg_num; iVar7 = iVar7 + 1) {
    pcVar8 = (code *)*puVar6;
    iVar2 = (*(code *)*puVar4)();
    uVar3 = (*pcVar8)();
    bVar1 = bVar1 | iVar2 != 0;
    if (((iVar2 != 0) && (0 < (int)uVar3)) && ((int)uVar3 < (int)uVar5)) {
      uVar5 = uVar3;
    }
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  DAT_00758cfa = (undefined2)uVar5;
  stats_nbr_expire_time = (int)((uVar5 & 0xffff) * 3 + 1) >> 1;
  DAT_00758cf5 = bVar1;
  FUN_00407f30(l_stats_data);
  return;
}

