// func mac_auth_db_mlo_mac_get_bind_status @ 00456658 size=884

int mac_auth_db_mlo_mac_get_bind_status
              (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char *__format;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  int in_stack_0000001c;
  int *in_stack_00000020;
  int local_38 [4];
  
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  if (in_stack_0000001c == 0) {
    return -1;
  }
  piVar14 = local_38 + 1;
  bVar1 = false;
  iVar13 = 0;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  FUN_004082d0(DAT_00766ff4,0xffffffff);
  iVar2 = FUN_00407fa0(DAT_00767008,(int)&local_res0 + 1);
  piVar12 = piVar14;
  iVar9 = (int)&local_res4 + 3;
  while (iVar13 < (int)(local_res0 >> 0x18)) {
    iVar13 = iVar13 + 1;
    iVar15 = iVar9 + 6;
    iVar3 = FUN_00407fa0(DAT_00767008,iVar9);
    *piVar12 = iVar3;
    piVar12 = piVar12 + 1;
    iVar9 = iVar15;
    if (iVar3 != 0) {
      bVar1 = true;
    }
  }
  if (iVar2 == 0) {
    if (!bVar1) {
      if (macauth_debug_switch == 0) {
        iVar9 = *(int *)(in_stack_0000001c + 0x184);
      }
      else {
        printf("[MACAUTH_DEBUG]%s()/%d mlo mac entry all not found.\n",
               "mac_auth_db_mlo_mac_get_bind_status",0x82c);
        iVar9 = *(int *)(in_stack_0000001c + 0x184);
      }
      iVar13 = -1;
      if (iVar9 == 1) {
        *in_stack_00000020 = 1;
        iVar13 = 0;
      }
      goto LAB_00456830;
    }
    goto LAB_00456778;
  }
  iVar13 = mac_auth_db_mac_get_vlan_bind_status(iVar2 + 0xa0,0,in_stack_0000001c,local_38);
  if (iVar13 != 0) goto LAB_00456830;
  *in_stack_00000020 = local_38[0];
  if (*(int *)(in_stack_0000001c + 0x184) == 1) {
    if (local_38[0] != 0) goto LAB_00456778;
    if (macauth_debug_switch == 0) goto LAB_00456830;
    uVar4 = (uint)*(byte *)(iVar2 + 0xa1);
    uVar11 = (uint)*(byte *)(iVar2 + 0xa0);
    __format = "[MACAUTH_DEBUG]%s()/%d mac[%02X:%02X:%02X:%02X:%02X:%02X]is binding black,break.\n";
    uVar5 = (uint)*(byte *)(iVar2 + 0xa2);
    uVar10 = 0x843;
    uVar6 = (uint)*(byte *)(iVar2 + 0xa3);
    uVar7 = (uint)*(byte *)(iVar2 + 0xa4);
    uVar8 = (uint)*(byte *)(iVar2 + 0xa5);
  }
  else if ((*(int *)(in_stack_0000001c + 0x184) == 0) && (local_38[0] == 1)) {
    if (macauth_debug_switch == 0) goto LAB_00456830;
    uVar4 = (uint)*(byte *)(iVar2 + 0xa1);
    uVar11 = (uint)*(byte *)(iVar2 + 0xa0);
    __format = "[MACAUTH_DEBUG]%s()/%d mac[%02X:%02X:%02X:%02X:%02X:%02X]is binding white,break.\n";
    uVar5 = (uint)*(byte *)(iVar2 + 0xa2);
    uVar10 = 0x84a;
    uVar6 = (uint)*(byte *)(iVar2 + 0xa3);
    uVar7 = (uint)*(byte *)(iVar2 + 0xa4);
    uVar8 = (uint)*(byte *)(iVar2 + 0xa5);
  }
  else {
LAB_00456778:
    iVar9 = 0;
    do {
      while( true ) {
        if ((int)(local_res0 >> 0x18) <= iVar9) {
          iVar13 = 0;
          goto LAB_00456830;
        }
        iVar2 = *piVar14;
        if (iVar2 != 0) break;
LAB_00456878:
        iVar9 = iVar9 + 1;
        piVar14 = piVar14 + 1;
      }
      iVar13 = mac_auth_db_mac_get_vlan_bind_status(iVar2 + 0xa0,0,in_stack_0000001c,local_38);
      if (iVar13 != 0) goto LAB_00456830;
      *in_stack_00000020 = local_38[0];
      if (*(int *)(in_stack_0000001c + 0x184) == 1) {
        if (local_38[0] != 0) goto LAB_00456878;
        if (macauth_debug_switch == 0) goto LAB_00456830;
        uVar4 = (uint)*(byte *)(iVar2 + 0xa1);
        uVar11 = (uint)*(byte *)(iVar2 + 0xa0);
        __format = 
        "[MACAUTH_DEBUG]%s()/%d mac[%02X:%02X:%02X:%02X:%02X:%02X]is binding black,break.\n";
        uVar5 = (uint)*(byte *)(iVar2 + 0xa2);
        uVar10 = 0x85f;
        uVar6 = (uint)*(byte *)(iVar2 + 0xa3);
        uVar7 = (uint)*(byte *)(iVar2 + 0xa4);
        uVar8 = (uint)*(byte *)(iVar2 + 0xa5);
        goto LAB_00456824;
      }
      if (*(int *)(in_stack_0000001c + 0x184) != 0) goto LAB_00456878;
      piVar14 = piVar14 + 1;
      iVar9 = iVar9 + 1;
    } while (local_38[0] != 1);
    if (macauth_debug_switch == 0) goto LAB_00456830;
    uVar4 = (uint)*(byte *)(iVar2 + 0xa1);
    uVar11 = (uint)*(byte *)(iVar2 + 0xa0);
    __format = "[MACAUTH_DEBUG]%s()/%d mac[%02X:%02X:%02X:%02X:%02X:%02X]is binding white,break.\n";
    uVar5 = (uint)*(byte *)(iVar2 + 0xa2);
    uVar10 = 0x865;
    uVar6 = (uint)*(byte *)(iVar2 + 0xa3);
    uVar7 = (uint)*(byte *)(iVar2 + 0xa4);
    uVar8 = (uint)*(byte *)(iVar2 + 0xa5);
  }
LAB_00456824:
  printf(__format,"mac_auth_db_mlo_mac_get_bind_status",uVar10,uVar11,uVar4,uVar5,uVar6,uVar7,uVar8)
  ;
LAB_00456830:
  FUN_00407f30(DAT_00766ff4);
  return iVar13;
}

