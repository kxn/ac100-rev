// func send_proxy_url_info_test @ 005337ac size=1

undefined4 send_proxy_url_info_test(undefined2 param_1)

{
  void *__s;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uStack_80;
  int iStack_7c;
  int iStack_78;
  char acStack_74 [88];
  
  pcVar6 = acStack_74 + 0x10;
  iStack_78 = 0;
  iStack_7c = 0;
  uStack_80 = 0;
  memset(pcVar6,0,0x40);
  acStack_74[0] = '\0';
  acStack_74[1] = '\0';
  acStack_74[2] = '\0';
  acStack_74[3] = '\0';
  acStack_74[4] = '\0';
  acStack_74[5] = '\0';
  acStack_74[6] = '\0';
  acStack_74[7] = '\0';
  acStack_74[8] = '\0';
  acStack_74[9] = '\0';
  acStack_74[10] = '\0';
  acStack_74[0xb] = '\0';
  acStack_74[0xc] = '\0';
  acStack_74[0xd] = '\0';
  acStack_74[0xe] = '\0';
  acStack_74[0xf] = '\0';
  apmngr_suy_proxy_info_get(&iStack_78,&iStack_7c,&uStack_80,0,0,pcVar6,0x40);
  if (iStack_78 == 0) {
    return 0xffffffff;
  }
  if (iStack_7c == 0) {
    return 0xffffffff;
  }
  __s = (void *)FUN_00408450(iStack_7c + 1,0x62d);
  if (__s == (void *)0x0) {
    return 0xffffffff;
  }
  memset(__s,0,iStack_7c + 1);
  apmngr_suy_proxy_info_get(0,0,0,__s,iStack_7c,0,0);
  iVar1 = json_object_new_object();
  uVar2 = json_object_new_object();
  uVar3 = json_object_new_object();
  snprintf(acStack_74,0x10,"%d",uStack_80);
  uVar4 = json_object_new_string(&DAT_00697f28);
  json_object_object_add(iVar1,"method",uVar4);
  uVar4 = json_object_new_string(pcVar6);
  json_object_object_add(uVar3,"proxy_protocol",uVar4);
  uVar4 = json_object_new_string(acStack_74);
  json_object_object_add(uVar3,"proxy_url_port",uVar4);
  uVar4 = json_object_new_string(__s);
  json_object_object_add(uVar3,"proxy_url_uri",uVar4);
  json_object_object_add(uVar2,"notify_proxy_url_info",uVar3);
  json_object_object_add(iVar1,"cloud_status",uVar2);
  uVar2 = json_object_to_json_string_ext(iVar1,0);
  if ((apmngr_debug_switch != '\0') && (iVar5 = is_target_debug_ap(0), iVar5 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d get send tdcp_msg:%s\n","apmngr_proxy_url_info_pkt_send",0x646,
           uVar2);
  }
  iVar5 = tdcp_send_request_to_ap_by_id(0,"notify_proxy_url_info",uVar2,5,param_1);
  if (iVar5 == 0) {
    uVar2 = 0;
    if ((apmngr_debug_switch == '\0') || (iVar5 = is_target_debug_ap(), iVar5 == 0))
    goto LAB_0052cc10;
    pcVar6 = "[APMNGR_DEBUG]%s()/%d send ap proxy url prefix to AP successfully.\n";
    uVar3 = 0x64f;
  }
  else {
    uVar2 = 0xffffffff;
    if ((apmngr_err_switch == '\0') || (iVar5 = is_target_debug_ap(), iVar5 == 0))
    goto LAB_0052cc10;
    pcVar6 = "[APMNGR_ERROR]%s()/%d send notify_proxy_url_info to ap failed!\n";
    uVar3 = 0x64a;
  }
  printf(pcVar6,"apmngr_proxy_url_info_pkt_send",uVar3);
LAB_0052cc10:
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  FUN_00407df0(__s);
  return uVar2;
}

