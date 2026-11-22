// func _cloud_portal_update_dns @ 00418cec size=1092

void _cloud_portal_update_dns(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint __seconds;
  sockaddr *psVar4;
  addrinfo *paVar5;
  char *__s1;
  addrinfo *local_78;
  addrinfo aStack_74;
  char local_54 [44];
  
  __seconds = 0x1e;
  do {
    sleep(__seconds);
    if ((0 < cloud_server_num) && (iVar1 = wportal_db_had_cloud_auth(), iVar1 != 0)) {
      memset(&g_cloud_portal_host_name,0,0x100);
      FUN_004082d0(wportal_cloud_server_update_mutex,0xffffffff);
      memset(&cloud_server_ip,0,0x280);
      cloud_server_num = 0;
      _wportal_wserv_add_or_del_old_ftt(0);
      memset(&cloud_server_old_ip,0,0x280);
      old_cloud_server_num = 0;
      FUN_00407f30(wportal_cloud_server_update_mutex);
    }
    if (g_cloud_portal_host_name != '\0') {
      local_78 = (addrinfo *)0x0;
      memset(local_54,0,0x28);
      memset(&aStack_74,0,0x20);
      aStack_74.ai_family = 2;
      aStack_74.ai_socktype = 1;
      iVar1 = getaddrinfo(&g_cloud_portal_host_name,(char *)0x0,&aStack_74,&local_78);
      if (iVar1 == 0) {
        if (local_78 == (addrinfo *)0x0) {
          if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_ERR]%s()/%d getaddrinfo failed.\n","_cloud_portal_update_dns_to_ap",
                   0x2f52);
          }
          goto LAB_00418d64;
        }
        FUN_004082d0(wportal_cloud_server_update_mutex,0xffffffff);
        for (paVar5 = local_78; paVar5 != (addrinfo *)0x0; paVar5 = paVar5->ai_next) {
          if (wportal_debug_switch == 0) {
            psVar4 = paVar5->ai_addr;
          }
          else {
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              psVar4 = paVar5->ai_addr;
            }
            else {
              printf("[WPORTAL_DBG]%s()/%d Query dns for %s, result: %x\n\n",
                     "_cloud_portal_update_dns_to_ap",0x2f59,&g_cloud_portal_host_name,
                     *(undefined4 *)(paVar5->ai_addr->sa_data + 2));
              psVar4 = paVar5->ai_addr;
            }
          }
          __s1 = &cloud_server_ip;
          inet_ntop(2,psVar4->sa_data + 2,local_54,0x28);
          for (iVar1 = 0; iVar3 = cloud_server_num, iVar1 < cloud_server_num; iVar1 = iVar1 + 1) {
            iVar2 = strcmp(__s1,local_54);
            __s1 = __s1 + 0x28;
            if (iVar2 == 0) break;
          }
          if (iVar1 == iVar3) {
            iVar1 = 1;
            goto LAB_00418ea8;
          }
        }
        iVar1 = 0;
LAB_00418ea8:
        if ((old_cloud_server_num == 0) && (cloud_server_num != 0)) {
          old_cloud_server_num = cloud_server_num;
          memset(&cloud_server_old_ip,0,0x280);
          memcpy(&cloud_server_old_ip,&cloud_server_ip,0x280);
          if (iVar1 == 0) {
            _wportal_flush_free_all();
          }
        }
        if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d is_need_update[%d]\n","_cloud_portal_update_dns_to_ap",0x2f77
                 ,iVar1);
        }
        if (iVar1 != 0) {
          cloud_server_num = 0;
          memset(&cloud_server_ip,0,0x280);
          paVar5 = local_78;
          while (paVar5 != (addrinfo *)0x0) {
            memset(local_54,0,0x28);
            inet_ntop(2,paVar5->ai_addr->sa_data + 2,local_54,0x28);
            iVar1 = cloud_server_num;
            if (0xf < cloud_server_num) break;
            iVar3 = strcmp(local_54,"0.0.0.0");
            if (iVar3 == 0) {
              paVar5 = paVar5->ai_next;
            }
            else if (local_54[0] == '\0') {
              paVar5 = paVar5->ai_next;
            }
            else {
              strncpy(&cloud_server_ip + iVar1 * 0x28,local_54,0x27);
              paVar5 = paVar5->ai_next;
              cloud_server_num = iVar1 + 1;
            }
          }
          if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_DBG]%s()/%d cloud_server_num[%d]\n","_cloud_portal_update_dns_to_ap",
                   0x2f91,cloud_server_num);
          }
          if (0 < cloud_server_num) {
            _wportal_flush_free_all();
            old_cloud_server_num = cloud_server_num;
            memset(&cloud_server_old_ip,0,0x280);
            memcpy(&cloud_server_old_ip,&cloud_server_ip,0x280);
          }
        }
        FUN_00407f30(wportal_cloud_server_update_mutex);
      }
      if (local_78 != (addrinfo *)0x0) {
        freeaddrinfo(local_78);
      }
    }
LAB_00418d64:
    __seconds = 10;
    if (old_cloud_server_num != 0) {
      __seconds = g_cloud_host_dns_upate_intvl;
    }
  } while( true );
}

