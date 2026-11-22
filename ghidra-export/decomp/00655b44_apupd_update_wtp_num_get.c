// func apupd_update_wtp_num_get @ 00655b44 size=620

undefined4 apupd_update_wtp_num_get(int param_1,int *param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *__format;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_300 [18];
  ushort local_2ee;
  
  iVar7 = 0;
  iVar3 = FUN_004081b0(param_1 + 0x7f4);
  do {
    if (iVar3 == 0) {
      *param_2 = iVar7;
      return 0;
    }
    iVar8 = iVar3 + 0x2e;
    iVar4 = apmngr_db_entry_get_by_mac(iVar8,auStack_300);
    if (iVar4 == -1) {
      if ((g_apupd_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        uVar6 = 0x91a;
        __format = "[APUPD_ERROR]%32s() %05d: get ap entry by mac failed.\r\n";
LAB_00655d48:
        printf(__format,"apupd_update_wtp_num_get",uVar6);
      }
    }
    else {
      iVar4 = FUN_00408430(iVar8);
      if (iVar4 == 0) {
        if ((*(uint *)(param_1 + 0x18) & 1) == 0) {
          if ((0x1ff < local_2ee) ||
             (uVar5 = local_2ee + 1,
             (*(uint *)(param_1 + (((int)uVar5 >> 5) + 6) * 4) >> (uVar5 & 0x1f) & 1) == 0))
          goto LAB_00655d04;
          iVar4 = *(int *)(param_1 + 0x7ec);
        }
        else {
          iVar4 = *(int *)(param_1 + 0x7ec);
        }
        if (iVar4 == 1) {
          iVar4 = FUN_00408430(iVar8);
          if (iVar4 == 0) {
            iVar7 = iVar7 + 1;
            *(undefined4 *)(iVar3 + 0x48) = 1;
            *(undefined4 *)(iVar3 + 0x54) = 1;
            goto LAB_00655bc8;
          }
          iVar4 = *(int *)(param_1 + 0x7ec);
        }
        else {
          iVar4 = *(int *)(param_1 + 0x7ec);
        }
        if (iVar4 == 2) {
          if (*(char *)(param_1 + 0x13a) == '\0') {
            if (*(int *)(param_1 + 0x130) != 0) {
              iVar4 = *(int *)(param_1 + 0x130);
              goto LAB_00655d64;
            }
            cVar2 = *(char *)(*(int *)(iVar3 + 0x50) + 0x138);
            if ((cVar2 != '\x01') && (cVar2 != '\x03')) {
              iVar4 = memcmp((void *)(iVar3 + 0x38),(void *)(param_1 + 0x1c4),0x10);
              if (iVar4 == 0) {
                iVar4 = *(int *)(param_1 + 0x130);
                goto LAB_00655d64;
              }
              if ((*(int *)(param_1 + 300) != 0) &&
                 (iVar4 = apupd_db_wtp_firmware_id_match(iVar3,param_1 + 0x1d4), iVar4 == 0)) {
                *(undefined4 *)(iVar3 + 0x48) = 0x10;
                goto LAB_00655bc8;
              }
            }
          }
          else {
            if (*(char *)(param_1 + 0x13a) == '\x01') goto LAB_00655da0;
            iVar4 = *(int *)(param_1 + 0x130);
LAB_00655d64:
            if (iVar4 != 1) {
              *(undefined4 *)(iVar3 + 0x48) = 0;
              goto LAB_00655bc8;
            }
          }
LAB_00655da0:
          iVar7 = iVar7 + 1;
          *(undefined4 *)(iVar3 + 0x48) = 1;
          *(undefined4 *)(iVar3 + 0x54) = 2;
        }
      }
      else {
LAB_00655d04:
        bVar1 = g_apupd_debug != 0;
        *(undefined4 *)(iVar3 + 0x48) = 0;
        if ((bVar1) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          __format = "[APUPD_DEBUG]%32s() %05d: ap not in upgrade group\r\n";
          uVar6 = 0x922;
          goto LAB_00655d48;
        }
      }
    }
LAB_00655bc8:
    iVar3 = FUN_00408680(iVar3);
  } while( true );
}

