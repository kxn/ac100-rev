// func balance_sta_connect_wtp_by_session @ 00457b40 size=536

undefined4 balance_sta_connect_wtp_by_session(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  int iVar13;
  char *__format;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if ((param_1 == (byte *)0x0) || (param_2 == (byte *)0x0)) {
    uVar15 = 0xffffffff;
    if ((g_balance_error != 0) && (iVar13 = is_target_debug_ap(), iVar13 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_sta_connect_wtp_by_session",
             0x61);
    }
  }
  else {
    memcpy(&local_2c,param_1,6);
    memcpy(&local_38,param_2,6);
    iVar13 = balance_db_dis_sta_check(&local_2c,&local_40);
    if (iVar13 == -1) {
      uVar15 = 0xffffffff;
      if (g_balance_warning == 0) {
        return 0xffffffff;
      }
      iVar13 = is_target_debug_ap();
      if (iVar13 == 0) {
        return 0xffffffff;
      }
      bVar1 = param_2[1];
      bVar2 = *param_2;
      __format = 
      "[BALANCE_WARNING](%32s) %05d: balance rejucts station(%02x:%02x:%02x:%02x:%02x:%02x) connects to wtp(%02x:%02x:%02x:%02x:%02x:%02x).\r\n"
      ;
      bVar3 = param_2[2];
      uVar14 = 0x6a;
      bVar4 = param_2[3];
      bVar5 = param_2[4];
      bVar6 = param_2[5];
      bVar7 = *param_1;
      bVar8 = param_1[1];
      bVar9 = param_1[2];
      bVar10 = param_1[3];
      bVar11 = param_1[4];
      bVar12 = param_1[5];
    }
    else {
      uVar15 = 0;
      if (g_balance_warning == 0) {
        return 0;
      }
      iVar13 = is_target_debug_ap();
      if (iVar13 == 0) {
        return 0;
      }
      bVar1 = param_2[1];
      bVar2 = *param_2;
      __format = 
      "[BALANCE_WARNING](%32s) %05d: balance accepts station(%02x:%02x:%02x:%02x:%02x:%02x) connects to wtp(%02x:%02x:%02x:%02x:%02x:%02x).\r\n"
      ;
      bVar3 = param_2[2];
      uVar14 = 0x6d;
      bVar4 = param_2[3];
      bVar5 = param_2[4];
      bVar6 = param_2[5];
      bVar7 = *param_1;
      bVar8 = param_1[1];
      bVar9 = param_1[2];
      bVar10 = param_1[3];
      bVar11 = param_1[4];
      bVar12 = param_1[5];
    }
    printf(__format,"balance_sta_connect_wtp_by_session",uVar14,(uint)bVar2,(uint)bVar1,(uint)bVar3,
           (uint)bVar4,(uint)bVar5,(uint)bVar6,(uint)bVar7,(uint)bVar8,(uint)bVar9,(uint)bVar10,
           (uint)bVar11,(uint)bVar12);
  }
  return uVar15;
}

