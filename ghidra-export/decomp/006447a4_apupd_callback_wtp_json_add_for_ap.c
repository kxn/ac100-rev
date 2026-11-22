// func apupd_callback_wtp_json_add_for_ap @ 006447a4 size=320

undefined4 apupd_callback_wtp_json_add_for_ap(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar3 = 0xc67;
  }
  else {
    iVar1 = json_object_new_object();
    if (iVar1 != 0) {
      iVar2 = apupd_wtp_from_struct_to_json_for_ap(param_1,iVar1);
      if (iVar2 != -1) {
        json_object_array_add(param_2,iVar1);
        return 0;
      }
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: turn log to json failed.\r\n",
               "apupd_callback_wtp_json_add_for_ap",0xc75);
      }
      json_object_put(iVar1);
      return 0xffffffff;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: malloc json obj failed.\r\n";
    uVar3 = 0xc6e;
  }
  printf(__format,"apupd_callback_wtp_json_add_for_ap",uVar3);
  return 0xffffffff;
}

