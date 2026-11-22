// func nms_stat_obj_send_to_cloud @ 004959a8 size=216

undefined4 nms_stat_obj_send_to_cloud(undefined4 param_1,undefined4 param_2)

{
  char *__s;
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  
  __s = (char *)json_object_to_json_string_ext(param_2,0);
  if ((__s == (char *)0x0) || (sVar1 = strlen(__s), 0x3ffff < sVar1)) {
    uVar3 = 0xffffffff;
    if (cloud_mngt_err_switch != '\0') {
      sVar1 = 0;
      if (__s != (char *)0x0) {
        sVar1 = strlen(__s);
      }
      uVar3 = 0xffffffff;
      printf("[CLOUD_MNGT_ERROR]%s()/%d packet(%d) to send is too long\n",
             "nms_stat_obj_send_to_cloud",0x5bb,sVar1);
    }
  }
  else {
    iVar2 = cloud_mngt_send_to_cloud(param_1,__s);
    uVar3 = 0;
    if ((iVar2 != 0) && (uVar3 = 0xffffffff, cloud_mngt_debug_switch != '\0')) {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_send_to_cloud failed\n",
             "nms_stat_obj_send_to_cloud",0x5c2);
    }
  }
  return uVar3;
}

