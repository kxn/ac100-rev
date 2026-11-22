// func mac_auth_db_mac_get_ssid_bind_status @ 00456510 size=328

undefined4
mac_auth_db_mac_get_ssid_bind_status
          (byte *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_004082d0(DAT_00766ff4,0xffffffff);
  puVar1 = (uint *)FUN_00407fa0(DAT_00767008,param_1);
  if (puVar1 == (uint *)0x0) {
    if (macauth_debug_switch == 0) {
      iVar3 = *(int *)(param_3 + 0x184);
    }
    else {
      printf("[MACAUTH_DEBUG]%s()/%d mac entry[%02X:%02X:%02X:%02X:%02X:%02X] not found.\n",
             "mac_auth_db_mac_get_ssid_bind_status",0x7f5,(uint)*param_1,(uint)param_1[1],
             (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
      iVar3 = *(int *)(param_3 + 0x184);
    }
    uVar4 = 0xffffffff;
    if (iVar3 != 1) goto LAB_004565a0;
    *param_4 = 1;
  }
  else {
    uVar2 = 1 << (*puVar1 & 0x1f) & *(uint *)(*(int *)(param_3 + 0x180) + (*puVar1 >> 5) * 4);
    if (*(int *)(param_3 + 0x184) == 0) {
      if (uVar2 == 0) {
        *param_4 = 0;
      }
      else {
LAB_004565e4:
        *param_4 = 1;
      }
    }
    else if (*(int *)(param_3 + 0x184) == 1) {
      if (uVar2 == 0) goto LAB_004565e4;
      *param_4 = 0;
    }
    else {
      *param_4 = 0;
    }
  }
  uVar4 = 0;
LAB_004565a0:
  FUN_00407f30(DAT_00766ff4);
  return uVar4;
}

