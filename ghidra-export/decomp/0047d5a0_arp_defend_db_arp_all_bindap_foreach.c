// func arp_defend_db_arp_all_bindap_foreach @ 0047d5a0 size=932

int arp_defend_db_arp_all_bindap_foreach(uint param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  void *__dest;
  int iVar7;
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
        return -1;
      }
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid callback.\n","arp_defend_db_arp_all_bindap_foreach",
             0x7ef);
      return -1;
    }
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < g_arp_defend_profile)) {
      FUN_0051ad88(&local_38);
      __dest = (void *)0x0;
      iVar1 = 0;
      iVar7 = 0;
      FUN_004082d0(DAT_007670f8,0xffffffff);
LAB_0047d680:
      do {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        iVar6 = 0;
        if (iVar2 + iVar3 <= iVar7) {
LAB_0047d844:
          FUN_00407f30(DAT_007670f8);
          if (iVar6 != 0) {
            if (iVar1 != 0) {
              FUN_00407df0(iVar1);
            }
            if (__dest != (void *)0x0) {
              FUN_00407df0(__dest);
            }
          }
          iVar1 = FUN_004081b0(&local_38);
          while (iVar1 != 0) {
            iVar7 = FUN_00408680(iVar1);
            (*param_2)(iVar1 + 0xc,param_3);
            FUN_00408500(iVar1);
            FUN_00407df0(*(undefined4 *)(iVar1 + 0x18));
            FUN_00407df0(iVar1);
            iVar1 = iVar7;
          }
          return iVar6;
        }
        iVar2 = iVar7 * 0x10;
        iVar3 = *(int *)(DAT_00767104 + iVar2);
        if (iVar3 < 0) {
LAB_0047d744:
          iVar3 = *(int *)(DAT_00767104 + iVar2);
          if (iVar3 < 50000) {
            iVar7 = iVar7 + 1;
            goto LAB_0047d680;
          }
          iVar6 = apmngr_db_get_sensor_max();
          if (iVar6 + 50000 <= iVar3) {
            iVar7 = iVar7 + 1;
            goto LAB_0047d680;
          }
        }
        else {
          iVar6 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          if (iVar6 + iVar4 <= iVar3) goto LAB_0047d744;
        }
        iVar3 = 0;
        if (DAT_007670f0 != 0) {
          iVar6 = *(int *)(DAT_00767104 + iVar2 + 0xc);
          while (*(uint *)(iVar6 + iVar3 * 4) != param_1) {
            iVar3 = iVar3 + 1;
            if (iVar3 == DAT_007670f0) goto LAB_0047d71c;
            iVar6 = *(int *)(DAT_00767104 + iVar2 + 0xc);
          }
          iVar1 = FUN_004082a0(1,300,0x807);
          if (iVar1 == 0) {
            iVar6 = -1;
            if ((arp_defend_err_switch == 0) || (iVar7 = is_target_debug_ap(), iVar7 == 0))
            goto LAB_0047d844;
            uVar5 = 0x80a;
          }
          else {
            memcpy((void *)(iVar1 + 0xc),(void *)(DAT_00767104 + iVar2),0x10);
            __dest = (void *)FUN_004082a0(DAT_007670f0,4,0x810);
            if (__dest != (void *)0x0) {
              iVar7 = iVar7 + 1;
              memcpy(__dest,*(void **)(DAT_00767104 + iVar2 + 0xc),DAT_007670f0 << 2);
              *(void **)(iVar1 + 0x18) = __dest;
              FUN_004086b0(&local_38,iVar1);
              goto LAB_0047d680;
            }
            iVar6 = -1;
            if ((arp_defend_err_switch == 0) || (iVar7 = is_target_debug_ap(), iVar7 == 0))
            goto LAB_0047d844;
            uVar5 = 0x813;
          }
          iVar6 = -1;
          printf("[ARP_DEFEND_ERROR]%s()/%d no memory!\n","arp_defend_db_arp_all_bindap_foreach",
                 uVar5);
          goto LAB_0047d844;
        }
LAB_0047d71c:
        iVar7 = iVar7 + 1;
      } while( true );
    }
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp_id(%d).\n",
             "arp_defend_db_arp_all_bindap_foreach",0x7f4,param_1);
      return -1;
    }
  }
  return -1;
}

