// func ac_cmcc_portal_init @ 0043948c size=1880

undefined4 ac_cmcc_portal_init(void)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 uVar7;
  size_t __n;
  undefined4 local_90;
  undefined4 local_8c;
  sockaddr local_88;
  undefined4 local_78;
  undefined1 local_74 [4];
  char *local_70;
  char local_6c [20];
  undefined4 *local_58;
  undefined4 local_54;
  undefined4 local_50;
  char *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 *local_34;
  undefined4 local_30;
  
  iVar2 = FUN_0051eb48("wportal","cmcc_thread_num",&l_cmcc_thread_num);
  if (iVar2 != 0) {
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Get cmcc thread num profile info error!\n","ac_cmcc_portal_init",
             0x921);
    }
    l_cmcc_thread_num = 2;
  }
  local_58 = &local_8c;
  local_8c = 0;
  local_90 = 0;
  local_74._0_2_ = 0;
  local_74[2] = '\0';
  local_74[3] = '\0';
  local_6c[0] = '\0';
  local_6c[1] = '\0';
  local_6c[2] = '\0';
  local_6c[3] = '\0';
  local_6c[0xc] = '\0';
  local_6c[0xd] = '\0';
  local_6c[0xe] = '\0';
  local_6c[0xf] = '\n';
  local_70 = "cmcc_port";
  local_4c = "cmcc_portal_port";
  local_3c = 10;
  local_6c[4] = '\0';
  local_6c[5] = '\0';
  local_6c[6] = '\0';
  local_6c[7] = '\x01';
  local_50 = 1;
  local_44 = 1;
  local_38 = 1;
  local_34 = &local_90;
  local_6c[8] = '\0';
  local_6c[9] = '\0';
  local_6c[10] = '\0';
  local_6c[0xb] = '\0';
  local_6c[0x10] = '\0';
  local_6c[0x11] = '\x01';
  local_6c[0x12] = '\0';
  local_6c[0x13] = '\x04';
  local_54 = 0;
  local_48 = 0;
  local_40 = 0;
  local_36 = 4;
  local_30 = 0;
  iVar2 = FUN_00408120("authentication","portal",local_74,2);
  if (iVar2 == 0) {
    g_cmcc_port = local_8c;
    g_cmcc_portal_port = local_90;
  }
  else {
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d uci req parse failed.\n","_ac_cmcc_read_config",0x8fd);
    }
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Get cmcc config info error!\n","ac_cmcc_portal_init",0x928);
    }
  }
  iVar2 = wportal_db_cmcc_data_init();
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  local_90 = 0;
  local_88.sa_data[6] = '\0';
  local_88.sa_data[7] = '\0';
  local_88.sa_data[8] = '\0';
  local_88.sa_data[9] = '\0';
  local_88.sa_data[10] = '\0';
  local_88.sa_data[0xb] = '\0';
  local_88.sa_data[0xc] = '\0';
  local_88.sa_data[0xd] = '\0';
  local_88.sa_data[2] = '\0';
  local_88.sa_data[3] = '\0';
  local_88.sa_data[4] = '\0';
  local_88.sa_data[5] = '\0';
  local_88.sa_family = 2;
  local_88.sa_data._0_2_ = (sa_family_t)g_cmcc_port;
  cmcc_sockfd = socket(2,1,0);
  if (cmcc_sockfd < 0) {
    if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_004396c8;
    pcVar6 = "[WPORTAL_ERR]%s()/%d Create cmcc socket error\n\n";
    uVar7 = 0x7fe;
  }
  else {
    local_90 = 0x100000;
    iVar2 = setsockopt(cmcc_sockfd,0xffff,0x1001,&local_90,4);
    if (iVar2 == -1) {
      if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_004396c8;
      pcVar6 = "[WPORTAL_ERR]%s()/%d setsockopt cmcc_sockfd socket SO_SNDBUF error\n\n";
      uVar7 = 0x805;
    }
    else {
      local_90 = 1;
      iVar2 = setsockopt(cmcc_sockfd,0xffff,4,&local_90,4);
      if (iVar2 == -1) {
        if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_004396c8;
        pcVar6 = "[WPORTAL_ERR]%s()/%d setsockopt cmcc socket SO_REUSEADDR error\n\n";
        uVar7 = 0x80c;
      }
      else {
        iVar2 = bind(cmcc_sockfd,&local_88,0x10);
        if (iVar2 == -1) {
          if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_004396c8;
          pcVar6 = "[WPORTAL_ERR]%s()/%d setsockopt cmcc socket SO_SNDBUF error\n\n";
          uVar7 = 0x813;
        }
        else {
          local_70 = (char *)0x0;
          local_6c[0] = '\0';
          local_6c[1] = '\0';
          local_6c[2] = '\0';
          local_6c[3] = '\0';
          local_6c[4] = '\0';
          local_6c[5] = '\0';
          local_6c[6] = '\0';
          local_6c[7] = '\0';
          local_6c[8] = '\0';
          local_6c[9] = '\0';
          local_6c[10] = '\0';
          local_6c[0xb] = '\0';
          local_6c[0xc] = '\0';
          local_6c[0xd] = '\0';
          local_6c[0xe] = '\0';
          local_6c[0xf] = '\0';
          local_6c[0x10] = '\0';
          local_6c[0x11] = '\0';
          local_6c[0x12] = '\0';
          local_6c[0x13] = '\0';
          local_74[2] = '\0';
          local_74[3] = '\0';
          local_74._0_2_ = 10;
          memcpy(local_6c,in6addr_any,0x10);
          local_74._2_2_ = (short)g_cmcc_port;
          cmcc_sockfd_v6 = socket(10,1,0);
          if (cmcc_sockfd_v6 < 0) {
            if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_004396c8;
            pcVar6 = "[WPORTAL_ERR]%s()/%d Create cmcc socket v6 error\n\n";
            uVar7 = 0x820;
          }
          else {
            local_90 = 0x100000;
            iVar2 = setsockopt(cmcc_sockfd_v6,0xffff,0x1001,&local_90,4);
            if (iVar2 == -1) {
              if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_004396c8;
              pcVar6 = "[WPORTAL_ERR]%s()/%d setsockopt cmcc_sockfd socket v6 SO_SNDBUF error\n\n";
              uVar7 = 0x827;
            }
            else {
              local_90 = 1;
              iVar2 = setsockopt(cmcc_sockfd_v6,0xffff,4,&local_90,4);
              if (iVar2 == -1) {
                if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_004396c8;
                pcVar6 = "[WPORTAL_ERR]%s()/%d setsockopt cmcc socket v6 SO_REUSEADDR error\n\n";
                uVar7 = 0x82e;
              }
              else {
                iVar3 = bind(cmcc_sockfd_v6,(sockaddr *)local_74,0x1c);
                iVar2 = l_cmcc_thread_num;
                if (iVar3 != -1) {
                  local_88.sa_family = 0;
                  local_88.sa_data[0] = '\0';
                  local_88.sa_data[1] = '\0';
                  local_88.sa_data[2] = '\0';
                  local_88.sa_data[3] = '\0';
                  local_88.sa_data[4] = '\0';
                  local_88.sa_data[5] = '\0';
                  __n = l_cmcc_thread_num << 3;
                  local_88.sa_data[6] = '\0';
                  local_88.sa_data[7] = '\0';
                  local_88.sa_data[8] = '\0';
                  local_88.sa_data[9] = '\0';
                  local_88.sa_data[10] = '\0';
                  local_88.sa_data[0xb] = '\0';
                  local_88.sa_data[0xc] = '\0';
                  local_88.sa_data[0xd] = '\0';
                  local_78 = 0;
                  _cmcc_threads = (void *)FUN_00408450(__n,0x7bb);
                  if (_cmcc_threads == (void *)0x0) {
                    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                      pcVar6 = "[WPORTAL_ERR]%s()/%d Create cmcc threads structure error\n";
                      uVar7 = 0x7be;
LAB_00439b08:
                      printf(pcVar6,"_ac_cmcc_worker_thread_init",uVar7);
                    }
                  }
                  else {
                    iVar3 = 0;
                    memset(_cmcc_threads,0,__n);
                    while (iVar3 < iVar2) {
                      sprintf((char *)&local_88,"%s%d","/cmcc_worker",iVar3);
                      pvVar1 = _cmcc_threads;
                      iVar4 = FUN_00408460(&local_88,0x20,0x2c,4);
                      *(int *)((int)pvVar1 + iVar3 * 8 + 4) = iVar4;
                      if (iVar4 == -1) {
                        if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0))
                        {
                          pcVar6 = "[WPORTAL_ERR]%s()/%d Create msgq error\n";
                          uVar7 = 0x7ca;
                          goto LAB_00439b08;
                        }
                        break;
                      }
                      piVar5 = (int *)FUN_00408450(4,0x7ce);
                      pvVar1 = _cmcc_threads;
                      if (piVar5 == (int *)0x0) {
LAB_00439a9c:
                        iVar3 = iVar3 + 1;
                      }
                      else {
                        *piVar5 = iVar3;
                        iVar4 = FUN_004084e0((void *)((int)pvVar1 + iVar3 * 8),&local_88,
                                             _ac_cmcc_worker_thread,piVar5);
                        if (iVar4 == 0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          if (wportal_err_switch == 0) goto LAB_00439a9c;
                          iVar4 = is_target_debug_ap();
                          iVar3 = iVar3 + 1;
                          if (iVar4 != 0) {
                            printf("[WPORTAL_ERR]%s()/%d Create cmcc receive thread error\n",
                                   "_ac_cmcc_worker_thread_init",0x7d7);
                          }
                        }
                      }
                    }
                  }
                  iVar2 = FUN_004084e0(&_edata,"cmcc_recv",_ac_cmcc_recv_thread,&l_cmcc_thread_num);
                  if (iVar2 == 0) {
                    return 0;
                  }
                  if (wportal_err_switch == 0) {
                    return 0xffffffff;
                  }
                  iVar2 = is_target_debug_ap();
                  if (iVar2 == 0) {
                    return 0xffffffff;
                  }
                  printf("[WPORTAL_ERR]%s()/%d Create cmcc receive thread error\n",
                         "ac_cmcc_portal_init",0x963);
                  return 0xffffffff;
                }
                if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_004396c8;
                pcVar6 = "[WPORTAL_ERR]%s()/%d setsockopt cmcc socket v6 SO_SNDBUF error\n\n";
                uVar7 = 0x835;
              }
            }
          }
        }
      }
    }
  }
  printf(pcVar6,"_cmcc_socket_init",uVar7);
LAB_004396c8:
  if (cmcc_sockfd != -1) {
    close(cmcc_sockfd);
    cmcc_sockfd = -1;
  }
  if (cmcc_sockfd_v6 != -1) {
    close(cmcc_sockfd_v6);
    cmcc_sockfd_v6 = -1;
  }
  return 0xffffffff;
}

