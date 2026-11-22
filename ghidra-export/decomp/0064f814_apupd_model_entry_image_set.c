// func apupd_model_entry_image_set @ 0064f814 size=1376

undefined4 apupd_model_entry_image_set(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if (*(int *)(param_2 + 0x1ac) == 0) {
    iVar2 = apupd_model_entry_image_delete();
    if (iVar2 != -1) {
      return 0;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APUPD_ERROR]%32s() %05d: delete software failed.\r\n";
    uVar5 = 0xaa1;
    goto LAB_0064f940;
  }
  if (g_apupd_debug == 0) {
    iVar2 = *(int *)(param_1 + 0x1b0);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x1b0);
    }
    else {
      printf("[APUPD_DEBUG]%32s() %05d: apupd_model_entry_image_add, model_name = %s\r\n",
             "apupd_model_entry_image_add",0xa36,param_1 + 0x5c);
      iVar2 = *(int *)(param_1 + 0x1b0);
    }
  }
  if (iVar2 != 0) {
    if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: free image memory\r\n","apupd_model_entry_image_add",0xa3b);
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x1b0));
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    apupd_import_software_num = apupd_import_software_num - 1;
    if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
             "apupd_model_entry_image_add",0xa3f,apupd_import_software_num);
    }
  }
  uVar1 = apupd_import_software_num;
  if (apupd_import_software_num < APUPD_IMPORT_SOFTWARE_NUM_MAX) {
    *(undefined4 *)(param_1 + 0x1ac) = *(undefined4 *)(param_2 + 0x1ac);
    *(undefined4 *)(param_1 + 0x1b0) = *(undefined4 *)(param_2 + 0x1b0);
    memcpy((void *)(param_1 + 0x1b4),(void *)(param_2 + 0x1b4),0x10);
    if (*(char *)(param_1 + 0x13a) == '\0') {
      memcpy((void *)(param_1 + 0x1c4),(void *)(param_2 + 0x1c4),0x10);
      memcpy((void *)(param_1 + 0x1d4),(void *)(param_2 + 0x1d4),0x618);
      apupd_import_software_num = uVar1 + 1;
      if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
               "apupd_model_entry_image_add",0xa80,apupd_import_software_num);
      }
      if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: image memory: %p, %d\r\n","apupd_model_entry_image_add",
               0xa81,*(undefined4 *)(param_1 + 0x1b0),*(undefined4 *)(param_1 + 0x1ac));
      }
      iVar2 = apupd_model_entry_time_delete(param_1);
      if (iVar2 != -1) {
        return 0;
      }
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        pcVar4 = "[APUPD_ERROR]%32s() %05d: clear time failed.\r\n";
        uVar5 = 0xa86;
LAB_0064fc08:
        printf(pcVar4,"apupd_model_entry_image_add",uVar5);
      }
    }
    else {
      if (g_apupd_debug == 0) {
        iVar2 = *(int *)(param_1 + 0x1a4);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_1 + 0x1a4);
        }
        else {
          printf("[APUPD_DEBUG]%32s() %05d: set sub image date\r\n","apupd_model_entry_image_add",
                 0xa50);
          iVar2 = *(int *)(param_1 + 0x1a4);
        }
      }
      if (iVar2 == 0) {
        *(undefined1 *)(param_1 + 0x1a0) = 0;
        memcpy((void *)(param_1 + 0x1c4),(void *)(param_2 + 0x1c4),0x10);
        memcpy((void *)(param_1 + 0x1d4),(void *)(param_2 + 0x1d4),0x618);
        iVar2 = *(int *)(param_1 + 0x1a4);
      }
      else {
        *(char *)(param_1 + 0x1a0) = *(char *)(param_1 + 0x1a0) + '\x01';
        iVar2 = *(int *)(param_1 + 0x1a4);
      }
      *(int *)(param_1 + 0x1a4) = iVar2 + *(int *)(param_2 + 0x1ac);
      apupd_import_software_num = apupd_import_software_num + 1;
      if (g_apupd_debug == 0) {
        iVar2 = *(int *)(param_1 + 0x148);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_1 + 0x148);
        }
        else {
          printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                 "apupd_model_entry_image_add",0xa5d,apupd_import_software_num);
          iVar2 = *(int *)(param_1 + 0x148);
        }
      }
      *(undefined4 *)(param_1 + 0x1a8) = 0;
      if ((iVar2 == 0) && (*(int *)(param_1 + 0x1a4) == *(int *)(param_1 + 0x188))) {
        *(undefined1 *)(param_1 + 0x1a1) = 2;
      }
      if (*(int *)(param_1 + 0x13c) != -1) {
        FUN_00408060();
        *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
      }
      puVar3 = (undefined4 *)FUN_00408450(4,0xa6a);
      if (puVar3 == (undefined4 *)0x0) {
        if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar4 = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
          uVar5 = 0xa6d;
          goto LAB_0064fc08;
        }
      }
      else {
        *(undefined1 *)puVar3 = 0;
        *(undefined1 *)((int)puVar3 + 1) = 0;
        *(undefined1 *)((int)puVar3 + 2) = 0;
        *(undefined1 *)((int)puVar3 + 3) = 0;
        *puVar3 = *(undefined4 *)(param_1 + 0x58);
        iVar2 = FUN_00408340(600,0,apupd_update_model_sub_image_timer_callback,puVar3,
                             apupd_update_model_timer_argv_callback,"apupd_model_entry_image_add",
                             0xa72);
        *(int *)(param_1 + 0x13c) = iVar2;
        if (iVar2 != -1) {
          return 0;
        }
        if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: add timer failed.\r\n","apupd_model_entry_image_add",
                 0xa75);
        }
        FUN_00407df0(puVar3);
      }
    }
  }
  else if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: software number rearches the max number(%d).\r\n",
           "apupd_model_entry_image_add",0xa45,APUPD_IMPORT_SOFTWARE_NUM_MAX);
  }
  if (g_apupd_error == 0) {
    return 0xffffffff;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  pcVar4 = "[APUPD_ERROR]%32s() %05d: add software failed.\r\n";
  uVar5 = 0xaab;
LAB_0064f940:
  printf(pcVar4,"apupd_model_entry_image_set",uVar5);
  return 0xffffffff;
}

