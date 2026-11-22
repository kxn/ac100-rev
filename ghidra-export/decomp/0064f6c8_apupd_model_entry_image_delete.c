// func apupd_model_entry_image_delete @ 0064f6c8 size=332

undefined4 apupd_model_entry_image_delete(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  if (*(int *)(param_1 + 0x1b0) != 0) {
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: free image memory\r\n","apupd_model_entry_image_delete",
             0x9de);
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x1b0));
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    apupd_import_software_num = apupd_import_software_num + -1;
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
             "apupd_model_entry_image_delete",0x9e2,apupd_import_software_num);
    }
  }
  memset((void *)(param_1 + 0x1b4),0,0x10);
  memset((void *)(param_1 + 0x1c4),0,0x10);
  iVar1 = apupd_model_entry_time_delete(param_1);
  uVar2 = 0;
  if (((iVar1 == -1) && (uVar2 = 0xffffffff, g_apupd_error != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: delete model time failed.\r\n",
           "apupd_model_entry_image_delete",0x9ea);
  }
  return uVar2;
}

