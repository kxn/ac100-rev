// func arp_defend_bind_arp @ 00479bdc size=1196

uint arp_defend_bind_arp(char *param_1,int param_2,int param_3,uint *param_4)

{
  bool bVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int local_30;
  
  uVar8 = 0xffffffff;
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    if ((arp_defend_debug_switch != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d arp str is %s.\n","arp_defend_bind_arp",0x36b,param_1);
    }
    uVar8 = 0;
    sVar2 = strlen(param_1);
    if (sVar2 != 0) {
      uVar9 = 0;
      uVar3 = 0;
      uVar7 = 0;
      iVar10 = 0;
      while (iVar10 <= (int)sVar2) {
        uVar5 = (uint)(byte)param_1[iVar10];
        if (uVar5 - 0x30 < 10) {
          if (uVar3 < 2) {
            uVar7 = (uVar7 * 10 + uVar5) - 0x30;
            if (((int)uVar7 < 0) || (uVar3 = 1, g_arp_defend_profile <= uVar7)) {
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
            if (g_arp_defend_profile <= uVar8) {
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
              if ((arp_defend_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("[ARP_DEFEND_DEBUG]%s()/%d arp id is %d\n","arp_defend_bind_arp",0x386,uVar7)
                ;
              }
            }
            else if (param_3 == 1) {
              if ((arp_defend_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("[ARP_DEFEND_DEBUG]%s()/%d arp id is %d\n","arp_defend_bind_arp",0x389,uVar7)
                ;
              }
              FUN_004082d0(DAT_007670fc,0xffffffff);
              uVar8 = *(uint *)(DAT_0076710c + uVar7 * 0x120);
              if (((int)uVar8 < 0) || (g_arp_defend_profile <= uVar8)) {
                FUN_00407f30(DAT_007670fc);
                if (arp_defend_debug_switch == 0) {
                  return 0xffffffff;
                }
                iVar10 = is_target_debug_ap();
                if (iVar10 == 0) {
                  return 0xffffffff;
                }
                uVar6 = 0x38e;
LAB_00479f1c:
                printf("[ARP_DEFEND_DEBUG]%s()/%d ARP_DEFEND_GET_ARP_ENTRY_USED %d\n",
                       "arp_defend_bind_arp",uVar6,uVar7);
                return 0xffffffff;
              }
              FUN_00407f30(DAT_007670fc);
              if (((int)uVar9 < 0) || (DAT_007670f0 <= uVar9)) {
                return 0xfffffffd;
              }
              iVar4 = uVar9 * 4;
              uVar9 = uVar9 + 1;
              *(uint *)(param_2 + iVar4) = uVar7;
              if (param_4 != (uint *)0x0) {
                *param_4 = uVar9;
              }
            }
          }
          else {
            if (uVar3 != 3) {
              return 0xffffffff;
            }
            if ((int)uVar8 < (int)uVar7) {
              return 0xffffffff;
            }
            local_30 = uVar7 * 0x120;
            do {
              if (param_3 == 0) {
                if ((arp_defend_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                  printf("[ARP_DEFEND_DEBUG]%s()/%d arp id is %d\n","arp_defend_bind_arp",0x3a6,
                         uVar7);
                }
              }
              else if (param_3 == 1) {
                if ((arp_defend_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                  printf("[ARP_DEFEND_DEBUG]%s()/%d arp id is %d\n","arp_defend_bind_arp",0x3a9,
                         uVar7);
                }
                FUN_004082d0(DAT_007670fc,0xffffffff);
                if (((int)*(uint *)(DAT_0076710c + local_30) < 0) ||
                   (g_arp_defend_profile <= *(uint *)(DAT_0076710c + local_30))) {
                  FUN_00407f30(DAT_007670fc);
                  if (arp_defend_debug_switch == 0) {
                    return 0xffffffff;
                  }
                  iVar10 = is_target_debug_ap();
                  if (iVar10 == 0) {
                    return 0xffffffff;
                  }
                  uVar6 = 0x3ae;
                  goto LAB_00479f1c;
                }
                FUN_004082d0(DAT_007670fc,0xffffffff);
                if ((int)uVar9 < 0) {
                  return 0xfffffffd;
                }
                if (DAT_007670f0 <= uVar9) {
                  return 0xfffffffd;
                }
                *(uint *)(param_2 + uVar9 * 4) = uVar7;
                uVar9 = uVar9 + 1;
                if (param_4 != (uint *)0x0) {
                  *param_4 = uVar9;
                }
              }
              uVar7 = uVar7 + 1;
              local_30 = local_30 + 0x120;
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

