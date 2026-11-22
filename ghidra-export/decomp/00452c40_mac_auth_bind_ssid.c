// func mac_auth_bind_ssid @ 00452c40 size=620

undefined4
mac_auth_bind_ssid(char *param_1,int *param_2,int param_3,int *param_4,int param_5,int param_6)

{
  size_t sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  
  uVar6 = 0xffffffff;
  if ((param_1 != (char *)0x0) && (param_2 != (int *)0x0)) {
    if (macauth_debug_switch != 0) {
      printf("[MACAUTH_DEBUG]%s()/%d ssid str is %s.\n","mac_auth_bind_ssid",0x16c,param_1);
    }
    sVar1 = strlen(param_1);
    uVar6 = 0;
    if (0 < (int)sVar1) {
      iVar9 = sVar1 - 1;
      uVar11 = 0;
      piVar10 = param_2;
      do {
        uVar2 = (uint)(byte)param_1[iVar9];
        if (((9 < uVar2 - 0x30) && (5 < uVar2 - 0x61)) && (5 < uVar2 - 0x41)) {
          return 0xffffffff;
        }
        uVar8 = 0;
        iVar3 = transfer_hex_to_int();
        uVar2 = uVar11;
        piVar7 = piVar10;
        do {
          if ((iVar3 >> (uVar8 & 0x1f) & 1U) != 0) {
            uVar4 = wserv_profile_get_max_wservice();
            if (uVar4 <= uVar2) break;
            if (param_3 == 0) {
              if (macauth_debug_switch != 0) {
                printf("[MACAUTH_DEBUG]%s()/%d vlan id is %d\n","mac_auth_bind_ssid",0x180,uVar2);
              }
              param_2[uVar2 >> 5] = param_2[uVar2 >> 5] | 1 << (uVar2 & 0x1f);
            }
            else if (param_3 == 1) {
              if (macauth_debug_switch != 0) {
                pcVar5 = "unbind";
                if (param_6 == 0) {
                  pcVar5 = "bind";
                }
                printf("[MACAUTH_DEBUG]%s()/%d %s vlan id(%d)\n","mac_auth_bind_ssid",0x184,pcVar5,
                       uVar2);
              }
              if ((param_6 == 0) && (*piVar7 != -1)) {
                if (macauth_debug_switch == 0) {
                  return 0xfffffffe;
                }
                printf("[MACAUTH_DEBUG]%s()/%d vlan(%d) binded.\n","mac_auth_bind_ssid",0x187);
                return 0xfffffffe;
              }
              *piVar7 = param_5;
            }
            if (param_4 != (int *)0x0) {
              *param_4 = *param_4 + 1;
            }
          }
          uVar8 = uVar8 + 1;
          uVar2 = uVar2 + 1;
          piVar7 = piVar7 + 1;
        } while (uVar8 != 4);
        iVar9 = iVar9 + -1;
        uVar11 = uVar11 + 4;
        piVar10 = piVar10 + 4;
      } while (iVar9 != -1);
      uVar6 = 0;
    }
  }
  return uVar6;
}

