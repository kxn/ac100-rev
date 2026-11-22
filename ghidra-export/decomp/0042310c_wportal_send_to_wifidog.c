// func wportal_send_to_wifidog @ 0042310c size=732

undefined4 wportal_send_to_wifidog(int param_1,int param_2)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  char *pcVar4;
  size_t __n;
  ssize_t sVar5;
  int *piVar6;
  int iVar7;
  sockaddr local_90 [7];
  
  if (param_1 == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[WPORTAL_ERR]%s()/%d Para null\n";
    uVar3 = 0x3736;
  }
  else {
    if ((param_2 != 0x263) && (param_2 != 0x25e)) {
      json_object_put();
      if (wportal_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[WPORTAL_ERR]%s()/%d assoc_type invalid:%d\n","wportal_send_to_wifidog",0x373e,param_2
            );
      return 0xffffffff;
    }
    memset(local_90,0,0x6e);
    local_90[0].sa_family = 1;
    strcpy(local_90[0].sa_data,"/tmp/jcs.service.srv.wifidog");
    sVar2 = strlen(local_90[0].sa_data);
    iVar1 = json_object_new_object();
    if (iVar1 != 0) {
      uVar3 = json_object_new_string("wifidog");
      json_object_object_add(iVar1,"name",uVar3);
      uVar3 = 1;
      if ((param_2 == 0x263) || (uVar3 = 0, param_2 == 0x25e)) {
        uVar3 = json_object_new_int(uVar3);
        json_object_object_add(iVar1,&DAT_00679d2c,uVar3);
      }
      json_object_object_add(iVar1,"data",param_1);
      pcVar4 = (char *)json_object_to_json_string_ext(iVar1,0);
      if ((wportal_debug_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d send_str: %s \n","wportal_send_to_wifidog",0x375e,pcVar4);
      }
      do {
        __n = strlen(pcVar4);
        sVar5 = sendto(wifidog_fd,pcVar4,__n,0,local_90,sVar2 + 2);
        if (0 < sVar5) break;
        if ((wportal_debug_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d Send failed.\n","wportal_send_to_wifidog",0x3768);
        }
        piVar6 = __errno_location();
      } while ((*piVar6 == 0xb) || (*piVar6 == 4));
      json_object_put(iVar1);
      return 0;
    }
    json_object_put(param_1);
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[WPORTAL_ERR]%s()/%d JSON OBJ CREATE failed\n";
    uVar3 = 0x374d;
  }
  printf(pcVar4,"wportal_send_to_wifidog",uVar3);
  return 0xffffffff;
}

