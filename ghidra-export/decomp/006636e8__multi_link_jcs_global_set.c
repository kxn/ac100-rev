// func _multi_link_jcs_global_set @ 006636e8 size=1036

void _multi_link_jcs_global_set(undefined4 param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *__s2;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  char local_58 [12];
  uint local_4c;
  char local_48 [39];
  undefined1 local_21;
  
  local_58[0] = '\0';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  local_58[4] = '\0';
  local_58[5] = '\0';
  local_58[6] = '\0';
  local_58[7] = '\0';
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_4c = 0;
  memset(local_48,0,0x28);
  iVar3 = json_object_object_get(param_1,"enable");
  if (iVar3 != 0) {
    iVar4 = json_object_get_type(iVar3);
    iVar6 = 0;
    if (iVar4 == 6) {
      while (iVar6 < onoff_map) {
        pcVar5 = *(char **)(PTR__mt_onoff_00731f8c + iVar6 * 0x10);
        if (pcVar5 == (char *)0x0) {
          iVar6 = iVar6 + 1;
        }
        else {
          __s2 = (char *)json_object_get_string(iVar3);
          iVar4 = strcmp(pcVar5,__s2);
          if (iVar4 == 0) {
            iVar3 = *(int *)(PTR__mt_onoff_00731f8c + iVar6 * 0x10 + 0xc);
            goto LAB_00663780;
          }
          iVar6 = iVar6 + 1;
        }
      }
      if (jcs_err_switch != 0) {
        pcVar5 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
        goto LAB_00663a14;
      }
    }
    else if (jcs_err_switch != 0) {
      pcVar5 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00663a14:
      printf(pcVar5,"_multi_link_jcs_global_set",0x25a);
    }
  }
  if (jcs_err_switch == 0) {
    iVar3 = -1;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_multi_link_jcs_global_set"
           ,0x25a);
    iVar3 = -1;
  }
LAB_00663780:
  iVar4 = json_object_object_get(param_1,"priority");
  if (iVar4 == 0) {
LAB_006637c0:
    if (jcs_err_switch == 0) {
      uVar7 = 0xff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
             "_multi_link_jcs_global_set",0x25d);
      uVar7 = 0xff;
    }
  }
  else {
    iVar6 = json_object_get_type(iVar4);
    if (iVar6 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_multi_link_jcs_global_set",0x25d);
      }
      goto LAB_006637c0;
    }
    pcVar5 = (char *)json_object_get_string(iVar4);
    uVar7 = atoi(pcVar5);
    uVar7 = uVar7 & 0xff;
  }
  iVar4 = json_object_object_get(param_1,"backup_ip");
  if ((iVar4 == 0) || (iVar6 = json_object_get_type(iVar4), iVar6 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_multi_link_jcs_global_set",0x260);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar4);
  }
  strncpy(local_58,pcVar5,0xf);
  local_4c = local_4c & 0xffffff00;
  iVar4 = json_object_object_get(param_1,"backup_ip6");
  if ((iVar4 == 0) || (iVar6 = json_object_get_type(iVar4), iVar6 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_multi_link_jcs_global_set",0x263);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar4);
  }
  strncpy(local_48,pcVar5,0x27);
  local_21 = 0;
  if (g_multi_link_enable == iVar3) {
    if (iVar3 == 0) goto LAB_006638c4;
    iVar4 = strncmp(&g_multi_link_peer_addr,local_58,0x10);
    bVar1 = iVar4 != 0;
    iVar4 = strncmp(&g_multi_link_peer_addr_ipv6,local_48,0x28);
    bVar2 = iVar4 != 0;
    if (g_multi_link_priority != uVar7) {
      bVar1 = g_multi_link_peer_addr != '\0' || bVar1;
      bVar2 = g_multi_link_peer_addr_ipv6 != '\0' || bVar2;
    }
  }
  else if (g_multi_link_enable == 0) {
    bVar1 = local_58[0] != '\0';
    bVar2 = local_48[0] != '\0';
  }
  else {
    bVar1 = g_multi_link_peer_addr != '\0';
    bVar2 = g_multi_link_peer_addr_ipv6 != '\0';
  }
  if (bVar1) {
    if (bVar2) {
      _multi_link_reboot_tmo_handle(0);
    }
    else {
      _multi_link_ipv4_reboot_tmo_handle();
    }
  }
  else if (bVar2) {
    _multi_link_ipv6_reboot_tmo_handle(0);
  }
LAB_006638c4:
  g_multi_link_priority = (byte)uVar7;
  g_multi_link_enable = iVar3;
  strncpy(&g_multi_link_peer_addr,local_58,0xf);
  strncpy(&g_multi_link_peer_addr_ipv6,local_48,0x27);
  return;
}

