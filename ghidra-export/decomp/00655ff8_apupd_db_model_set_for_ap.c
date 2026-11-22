// func apupd_db_model_set_for_ap @ 00655ff8 size=1456

undefined4 apupd_db_model_set_for_ap(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  char *__format;
  
  if ((param_1 == 0) || (apupd_model_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_model_set_for_ap",0x1fe0);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_model_hash,param_1 + 0x58);
  if (iVar1 == 0) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto LAB_0065635c;
    __format = "[APUPD_ERROR]%32s() %05d: get model from hash by id failed.\r\n";
    uVar6 = 0x1fea;
  }
  else {
    memset((void *)(iVar1 + 0x18),0,0x40);
    memcpy((void *)(iVar1 + 0x18),(void *)(param_1 + 0x18),0x40);
    iVar2 = FUN_00407fa0(apupd_wtp_hash,param_2);
    if (iVar2 == 0) {
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
      goto LAB_0065635c;
      __format = "[APUPD_ERROR]%32s() %05d: get wtp from hash by mac failed.\r\n";
      uVar6 = 0x1ff2;
    }
    else {
      if (param_3 == 2) {
        if (*(char *)(param_1 + 0x13a) == '\0') {
          if (APUPD_IMPORT_SOFTWARE_NUM_MAX <= apupd_import_software_num) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
            goto LAB_006563f4;
            uVar6 = 0x1ffa;
LAB_006564a0:
            printf("[APUPD_ERROR]%32s() %05d: apupd_import_software_num exceeds max num.\r\n",
                   "apupd_db_model_set_for_ap",uVar6);
LAB_006563f4:
            FUN_00407f30(apupd_db_mutex);
            return 0xfffffffe;
          }
          pvVar5 = (void *)FUN_00408450(0x3c,0x1ffe);
          *(void **)(iVar2 + 0x8c) = pvVar5;
          if (pvVar5 == (void *)0x0) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
            goto LAB_0065635c;
            __format = "[APUPD_ERROR]%32s() %05d: malloc image info failed.\r\n";
            uVar6 = 0x2001;
            goto LAB_006563a0;
          }
          memset(pvVar5,0,0x3c);
          *(undefined4 *)(*(int *)(iVar2 + 0x8c) + 4) = *(undefined4 *)(param_1 + 0x1b0);
          **(undefined4 **)(iVar2 + 0x8c) = *(undefined4 *)(param_1 + 0x1ac);
          memcpy((void *)(*(int *)(iVar2 + 0x8c) + 8),(void *)(param_1 + 0x1b4),0x10);
          memcpy((void *)(iVar2 + 0x90),(void *)(param_1 + 0x1c4),0x10);
          apupd_import_software_num = apupd_import_software_num + 1;
          if (g_apupd_debug == 0) {
            *(undefined4 *)(iVar2 + 0x54) = 2;
          }
          else {
            iVar3 = is_target_debug_ap();
            if (iVar3 == 0) {
              *(undefined4 *)(iVar2 + 0x54) = 2;
            }
            else {
              printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                     "apupd_db_model_set_for_ap",0x200b,apupd_import_software_num);
              *(undefined4 *)(iVar2 + 0x54) = 2;
            }
          }
        }
        else if (*(char *)(param_1 + 0x13a) == '\x01') {
          if (APUPD_IMPORT_SOFTWARE_NUM_MAX <= apupd_import_software_num) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
            goto LAB_006563f4;
            uVar6 = 0x2011;
            goto LAB_006564a0;
          }
          pvVar5 = (void *)FUN_00408450(0x3c,0x2015);
          *(void **)(iVar2 + 0x8c) = pvVar5;
          if (pvVar5 == (void *)0x0) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
            goto LAB_0065635c;
            __format = "[APUPD_ERROR]%32s() %05d: malloc image info failed.\r\n";
            uVar6 = 0x2018;
            goto LAB_006563a0;
          }
          memset(pvVar5,0,0x3c);
          if (g_apupd_debug == 0) {
            iVar3 = *(int *)(iVar2 + 0x8c);
          }
          else {
            iVar3 = is_target_debug_ap();
            if (iVar3 == 0) {
              iVar3 = *(int *)(iVar2 + 0x8c);
            }
            else {
              printf("[APUPD_DEBUG]%32s() %05d: total_image_size = %d, total_image_piece = %d\r\n",
                     "apupd_db_model_set_for_ap",0x201d,*(undefined4 *)(param_1 + 0x188),
                     *(undefined4 *)(param_1 + 0x188));
              iVar3 = *(int *)(iVar2 + 0x8c);
            }
          }
          *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(param_1 + 0x188);
          *(undefined4 *)(*(int *)(iVar2 + 0x8c) + 0x1c) = *(undefined4 *)(param_1 + 0x18c);
          *(undefined1 *)(*(int *)(iVar2 + 0x8c) + 0x30) = 0;
          *(undefined1 *)(*(int *)(iVar2 + 0x8c) + 0x31) = 0;
          *(undefined4 *)(*(int *)(iVar2 + 0x8c) + 0x34) = 0;
          *(undefined4 *)(*(int *)(iVar2 + 0x8c) + 0x38) = 0;
          memcpy((void *)(*(int *)(iVar2 + 0x8c) + 0x20),(void *)(param_1 + 400),0x10);
          *(undefined4 *)(iVar2 + 0x54) = 2;
        }
        else {
          *(undefined4 *)(iVar2 + 0x54) = 2;
        }
      }
      else {
        *(int *)(iVar2 + 0x54) = param_3;
      }
      iVar3 = *(int *)(iVar1 + 0x140);
      if (((iVar3 == 0) || (iVar3 == 4)) || (iVar3 == 5)) {
        iVar3 = apupd_model_entry_time_set(iVar1,param_1);
        if (iVar3 != -1) {
          uVar6 = 1;
          goto LAB_00656124;
        }
        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
        goto LAB_0065635c;
        __format = "[APUPD_ERROR]%32s() %05d: set model time failed.\r\n";
        uVar6 = 0x202b;
      }
      else {
        if (iVar3 == 1) {
          *(undefined4 *)(iVar2 + 0x48) = 1;
          goto LAB_00656128;
        }
        iVar3 = FUN_00407fa0(apupd_update_model_hash,param_1 + 0x58);
        if (iVar3 != 0) {
          iVar4 = apupd_update_wtp_entry_add_check(iVar2);
          if (iVar4 == 0) {
            *(undefined4 *)(iVar2 + 0x48) = 1;
            goto LAB_00656128;
          }
          iVar3 = apupd_update_wtp_entry_add(iVar3,iVar2);
          if (iVar3 == 0) {
            uVar6 = 2;
            if (*(char *)(iVar1 + 0x13a) == '\0') {
              if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
              goto LAB_0065635c;
              __format = "[APUPD_ERROR]%32s() %05d: apupd_update_wtp_entry_add failed.\r\n";
              uVar6 = 0x2043;
              goto LAB_006563a0;
            }
          }
          else {
            uVar6 = 2;
          }
LAB_00656124:
          *(undefined4 *)(iVar2 + 0x48) = uVar6;
LAB_00656128:
          uVar6 = apupd_db_mutex;
          *(int *)(iVar1 + 0x144) = *(int *)(iVar1 + 0x144) + 1;
          FUN_00407f30(uVar6);
          return 0;
        }
        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
        goto LAB_0065635c;
        __format = "[APUPD_ERROR]%32s() %05d: get model from hash by id failed.\r\n";
        uVar6 = 0x203b;
      }
    }
  }
LAB_006563a0:
  printf(__format,"apupd_db_model_set_for_ap",uVar6);
LAB_0065635c:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

