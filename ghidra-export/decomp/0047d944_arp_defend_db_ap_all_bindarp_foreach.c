// func arp_defend_db_ap_all_bindarp_foreach @ 0047d944 size=1376

undefined4
arp_defend_db_ap_all_bindarp_foreach(int param_1,code *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint *__dest;
  int iVar3;
  char *__format;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if (param_2 == (code *)0x0) {
    if (arp_defend_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[ARP_DEFEND_ERROR]%s()/%d Invalid callback.\n";
      uVar7 = 0x850;
LAB_0047dd50:
      printf(__format,"arp_defend_db_ap_all_bindarp_foreach",uVar7);
      return 0xffffffff;
    }
  }
  else {
    if (-1 < param_1) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      if ((param_1 < iVar1 + iVar2) ||
         ((49999 < param_1 && (iVar1 = apmngr_db_get_sensor_max(), param_1 < iVar1 + 50000)))) {
        __dest = (uint *)FUN_004082a0(DAT_007670f0,4,0x859);
        if (__dest == (uint *)0x0) {
          if (arp_defend_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = "[ARP_DEFEND_ERROR]%s()/%d no memory.\n";
          uVar7 = 0x85c;
          goto LAB_0047dd50;
        }
        FUN_004082d0(DAT_007670f8,0xffffffff);
        iVar1 = DAT_00767104;
        iVar2 = param_1 << 4;
        if (49999 < param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar5 = apmngr_db_get_template_max();
          iVar2 = (param_1 + -50000 + iVar2 + iVar5) * 0x10;
        }
        iVar5 = DAT_00767104;
        if (-1 < *(int *)(iVar1 + iVar2)) {
          iVar1 = param_1 << 4;
          if (49999 < param_1) {
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x10;
          }
          iVar5 = *(int *)(iVar5 + iVar1);
          iVar1 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          if (iVar5 < iVar1 + iVar2) goto LAB_0047dad0;
        }
        iVar1 = DAT_00767104;
        iVar2 = param_1 << 4;
        if (49999 < param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar5 = apmngr_db_get_template_max();
          iVar2 = (param_1 + -50000 + iVar2 + iVar5) * 0x10;
        }
        iVar5 = DAT_00767104;
        if (49999 < *(int *)(iVar1 + iVar2)) {
          iVar1 = param_1 << 4;
          if (49999 < param_1) {
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x10;
          }
          iVar2 = *(int *)(iVar5 + iVar1);
          iVar1 = apmngr_db_get_sensor_max();
          if (iVar2 < iVar1 + 50000) {
LAB_0047dad0:
            iVar1 = DAT_00767104;
            iVar2 = param_1 << 4;
            if (49999 < param_1) {
              iVar2 = apmngr_db_get_ap_max();
              iVar5 = apmngr_db_get_template_max();
              iVar2 = (param_1 + -50000 + iVar2 + iVar5) * 0x10;
            }
            uVar6 = 0;
            memcpy(__dest,*(void **)(iVar1 + iVar2 + 0xc),DAT_007670f0 << 2);
            FUN_00407f30(DAT_007670f8);
            FUN_0051ad88(&local_38);
            FUN_004082d0(DAT_007670fc,0xffffffff);
            puVar4 = __dest;
LAB_0047db40:
            do {
              if (DAT_007670f0 <= uVar6) {
                uVar7 = 0;
LAB_0047dc58:
                iVar2 = 0;
                FUN_00407f30(DAT_007670fc);
                FUN_00407df0(__dest);
                *param_4 = 0;
                iVar1 = FUN_004081b0(&local_38);
                while (iVar1 != 0) {
                  iVar5 = FUN_00408680(iVar1);
                  iVar3 = (*param_2)(iVar2,iVar1 + 0xc,param_3);
                  if (iVar3 == 0) {
                    *param_4 = *param_4 + 1;
                    iVar2 = iVar2 + 1;
                    if ((arp_defend_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)
                       ) {
                      printf("[ARP_DEFEND_DEBUG]%s()/%d cursor: %d\n",
                             "arp_defend_db_ap_all_bindarp_foreach",0x891,iVar2);
                    }
                  }
                  FUN_00408500(iVar1);
                  FUN_00407df0(iVar1);
                  iVar1 = iVar5;
                }
                return uVar7;
              }
              if ((-1 < (int)*puVar4) && (*puVar4 < g_arp_defend_profile)) {
                iVar1 = FUN_004082a0(1,300,0x873);
                if (iVar1 == 0) {
                  uVar7 = 0xffffffff;
                  if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    printf("[ARP_DEFEND_ERROR]%s()/%d no memory!\n",
                           "arp_defend_db_ap_all_bindarp_foreach",0x876);
                  }
                  goto LAB_0047dc58;
                }
                uVar6 = uVar6 + 1;
                memcpy((void *)(iVar1 + 0xc),(void *)(DAT_0076710c + *puVar4 * 0x120),0x120);
                FUN_004086b0(&local_38,iVar1);
                puVar4 = puVar4 + 1;
                goto LAB_0047db40;
              }
              uVar6 = uVar6 + 1;
              puVar4 = puVar4 + 1;
            } while( true );
          }
        }
        if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[ARP_DEFEND_ERROR]%s()/%d ap_entry(%d) not used.\n",
                 "arp_defend_db_ap_all_bindarp_foreach",0x863,param_1);
        }
        FUN_00407f30(DAT_007670f8);
        return 0xffffffff;
      }
    }
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid ap_id(%d).\n","arp_defend_db_ap_all_bindarp_foreach"
             ,0x855,param_1);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

