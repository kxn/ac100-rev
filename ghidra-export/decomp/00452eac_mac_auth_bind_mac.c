// func mac_auth_bind_mac @ 00452eac size=424

undefined4 mac_auth_bind_mac(char *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    if (macauth_debug_switch != 0) {
      printf("[MACAUTH_DEBUG]%s()/%d mac str is %s.\n","mac_auth_bind_mac",0x1a8,param_1);
    }
    sVar2 = strlen(param_1);
    uVar1 = 0;
    if (0 < (int)sVar2) {
      iVar7 = sVar2 - 1;
      uVar8 = 0;
      do {
        uVar3 = (uint)(byte)param_1[iVar7];
        if (((9 < uVar3 - 0x30) && (5 < uVar3 - 0x61)) && (5 < uVar3 - 0x41)) {
          return 0xffffffff;
        }
        uVar6 = 0;
        iVar4 = transfer_hex_to_int();
        uVar3 = uVar8;
        do {
          if ((iVar4 >> (uVar6 & 0x1f) & 1U) != 0) {
            if (g_mac_auth_profile <= uVar3) break;
            if (macauth_debug_switch != 0) {
              printf("[MACAUTH_DEBUG]%s()/%d mac id is %d\n","mac_auth_bind_mac",0x1ba,uVar3);
            }
            puVar5 = (uint *)(param_2 + (uVar3 >> 5) * 4);
            *puVar5 = *puVar5 | 1 << (uVar3 & 0x1f);
            if (param_3 != (int *)0x0) {
              *param_3 = *param_3 + 1;
            }
          }
          uVar6 = uVar6 + 1;
          uVar3 = uVar3 + 1;
        } while (uVar6 != 4);
        iVar7 = iVar7 + -1;
        uVar8 = uVar8 + 4;
      } while (iVar7 != -1);
      uVar1 = 0;
    }
  }
  return uVar1;
}

