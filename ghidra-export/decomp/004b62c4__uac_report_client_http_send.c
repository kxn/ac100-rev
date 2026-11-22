// func _uac_report_client_http_send @ 004b62c4 size=404

undefined4 _uac_report_client_http_send(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = -1;
  curl_global_init(3);
  iVar1 = curl_easy_init();
  _g_curl = iVar1;
  if (iVar1 != 0) {
    curl_easy_setopt(iVar1,99,1);
    curl_easy_setopt(iVar1,0x4e,10);
    curl_easy_setopt(iVar1,0xd,10);
    curl_easy_setopt(iVar1,0x4e2b,_curl_no_output);
    curl_easy_setopt(iVar1,0x4ec3,_opensocket);
    curl_easy_setopt(iVar1,0x27b4,&_g_sockfd);
    curl_easy_setopt(iVar1,0x2712,&DAT_00767d71);
    uVar2 = curl_slist_append(0,"Content-Type:application/json;charset=UTF-8");
    curl_easy_setopt(iVar1,0x2727,uVar2);
    curl_easy_setopt(iVar1,0x2f,1);
    curl_easy_setopt(iVar1,0x271f,param_1);
    iVar4 = curl_easy_perform(iVar1);
    curl_slist_free_all(uVar2);
    curl_easy_cleanup(iVar1);
  }
  uVar2 = 0;
  curl_global_cleanup();
  _g_curl = 0;
  if ((iVar4 != 0) && (uVar2 = 0xffffffff, report_warning_switch != 0)) {
    uVar3 = curl_easy_strerror(iVar4);
    printf("[REPORT_WARNING]%s()/line %d : curl_easy_perform() failed: %s\n",
           "_uac_report_client_http_send",299,uVar3);
  }
  return uVar2;
}

