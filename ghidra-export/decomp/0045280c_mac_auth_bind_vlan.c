// func mac_auth_bind_vlan @ 0045280c size=996

uint mac_auth_bind_vlan(char *param_1,int param_2,int param_3,int *param_4,int param_5,int param_6)

{
  bool bVar1;
  size_t sVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  
  uVar8 = 0xffffffff;
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    if (macauth_debug_switch != 0) {
      printf("[MACAUTH_DEBUG]%s()/%d vlan str is %s.\n","mac_auth_bind_vlan",0xff,param_1);
    }
    uVar8 = 0;
    sVar2 = strlen(param_1);
    if (sVar2 != 0) {
      uVar3 = 0;
      uVar7 = 0;
      iVar10 = 0;
      while (iVar10 <= (int)sVar2) {
        uVar5 = (uint)(byte)param_1[iVar10];
        if (uVar5 - 0x30 < 10) {
          if (uVar3 < 2) {
            uVar7 = (uVar7 * 10 + uVar5) - 0x30;
            if (((int)uVar7 < 0) || (uVar3 = 1, DAT_00766fec + 1U <= uVar7)) {
              return 0xffffffff;
            }
            iVar10 = iVar10 + 1;
          }
          else if (uVar3 - 2 < 2) {
            uVar8 = (uVar8 * 10 + uVar5) - 0x30;
            if ((int)uVar8 < 0) {
              return 0xffffffff;
            }
            uVar3 = 3;
            if (DAT_00766fec + 1U <= uVar8) {
              return 0xffffffff;
            }
            iVar10 = iVar10 + 1;
          }
          else {
            iVar10 = iVar10 + 1;
          }
        }
        else if (uVar5 == 0x2d) {
          bVar1 = uVar3 != 1;
          uVar3 = 2;
          if (bVar1) {
            return 0xffffffff;
          }
          iVar10 = iVar10 + 1;
        }
        else {
          if ((uVar5 != 0x2c) && (uVar5 != 0)) {
            return 0xffffffff;
          }
          if (uVar3 == 1) {
            if (param_3 == 0) {
              if (macauth_debug_switch != 0) {
                printf("[MACAUTH_DEBUG]%s()/%d vlan id is %d\n","mac_auth_bind_vlan",0x11d,uVar7);
              }
              puVar4 = (uint *)(param_2 + (uVar7 >> 5) * 4);
              *puVar4 = *puVar4 | 1 << (uVar7 & 0x1f);
            }
            else if (param_3 == 1) {
              if (macauth_debug_switch != 0) {
                pcVar6 = "unbind";
                if (param_6 == 0) {
                  pcVar6 = "bind";
                }
                printf("[MACAUTH_DEBUG]%s()/%d %s vlan id(%d)\n","mac_auth_bind_vlan",0x121,pcVar6,
                       uVar7);
              }
              if ((param_6 == 0) && (*(int *)(param_2 + uVar7 * 4) != -1)) {
                if (macauth_debug_switch == 0) {
                  return 0xfffffffe;
                }
                printf("[MACAUTH_DEBUG]%s()/%d vlan(%d) binded.\n","mac_auth_bind_vlan",0x124);
                return 0xfffffffe;
              }
              *(int *)(param_2 + uVar7 * 4) = param_5;
            }
            if (param_4 != (int *)0x0) {
              *param_4 = *param_4 + 1;
            }
          }
          else {
            if (uVar3 != 3) {
              return 0xffffffff;
            }
            if ((int)uVar8 < (int)uVar7) {
              return 0xffffffff;
            }
            piVar9 = (int *)(param_2 + uVar7 * 4);
            do {
              if (param_3 == 0) {
                if (macauth_debug_switch != 0) {
                  printf("[MACAUTH_DEBUG]%s()/%d vlan id is %d\n","mac_auth_bind_vlan",0x134,uVar7);
                }
                puVar4 = (uint *)(param_2 + (uVar7 >> 5) * 4);
                *puVar4 = *puVar4 | 1 << (uVar7 & 0x1f);
              }
              else if (param_3 == 1) {
                if (macauth_debug_switch != 0) {
                  printf("[MACAUTH_DEBUG]%s()/%d vlan id is %d\n","mac_auth_bind_vlan",0x138,uVar7);
                }
                if ((param_6 == 0) && (*piVar9 != -1)) {
                  if (macauth_debug_switch == 0) {
                    return 0xfffffffe;
                  }
                  printf("[MACAUTH_DEBUG]%s()/%d %s vlan id(%d)\n","mac_auth_bind_vlan",0x13b,"bind"
                         ,uVar7);
                  return 0xfffffffe;
                }
                *piVar9 = param_5;
              }
              uVar7 = uVar7 + 1;
              if (param_4 != (int *)0x0) {
                *param_4 = *param_4 + 1;
              }
              piVar9 = piVar9 + 1;
            } while ((int)uVar7 <= (int)uVar8);
          }
          uVar3 = 0;
          uVar8 = 0;
          uVar7 = 0;
          iVar10 = iVar10 + 1;
        }
      }
      uVar8 = 0;
    }
  }
  return uVar8;
}

