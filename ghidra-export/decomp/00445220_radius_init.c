// func radius_init @ 00445220 size=2928

undefined4 radius_init(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  void *pvVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  undefined8 uVar11;
  undefined4 local_78;
  uint local_74;
  undefined2 local_70;
  char acStack_6c [32];
  char acStack_4c [36];
  
  memset(acStack_4c,0,0x20);
  local_74 = 0;
  local_70 = 0;
  uac_list_init(&g_radius_result_check_list);
  rh = radius_read_config("/etc/radius/radius.conf");
  if (rh == 0) {
    if (radius_err_switch == 0) {
      return 0xffffffff;
    }
    uVar8 = 0x130e;
    pcVar6 = "[RADIUS_ERR]%s()/%d Error opening radius configuration file\n";
  }
  else {
    iVar2 = radius_dictionary_init(rh);
    if (iVar2 == 0) {
      uVar8 = radius_conf_str(rh,"dictionary_dir");
      iVar2 = rh;
      uVar3 = radius_conf_str(rh,"root_dictionary");
      iVar2 = radius_read_dictionary(iVar2,uVar8,uVar3);
      puVar1 = PTR_DAT_007591ac;
      if (iVar2 == 0) {
        iVar2 = uac_profile_get_int("wportal","radius_thread_num",PTR_DAT_007591ac + 0x1294);
        if (iVar2 != 0) {
          if (radius_err_switch == 0) {
            *(undefined4 *)(puVar1 + 0x1294) = 4;
          }
          else {
            printf("[RADIUS_ERR]%s()/%d Get radius thread num profile info error!\n",
                   "_radius_profile_init",0xe32);
            *(undefined4 *)(puVar1 + 0x1294) = 4;
          }
        }
        iVar2 = uac_com_get_dev_mac(&local_74);
        if (iVar2 == 0) {
          sprintf(&device_mac,"%02x-%02x-%02x-%02x-%02x-%02x",local_74 >> 0x18,
                  local_74 >> 0x10 & 0xff,local_74 >> 8 & 0xff,local_74 & 0xff,(uint)local_70._0_1_,
                  (uint)(byte)local_70);
          sprintf(&default_nas_identifier,"%02X%02X%02X%02X%02X%02X",local_74 >> 0x18,
                  local_74 >> 0x10 & 0xff,local_74 >> 8 & 0xff,local_74 & 0xff,(uint)local_70._0_1_,
                  (uint)(byte)local_70);
          g_sess_id_mutex = uac_mutex_create("sess_id",1);
          if (g_sess_id_mutex == 0) {
            if (radius_err_switch == 0) {
              return 0xffffffff;
            }
            uVar8 = 0x1334;
            pcVar6 = "[RADIUS_ERR]%s()/%d Create mutex error\n";
          }
          else {
            memset(acStack_6c,0,0x20);
            local_78 = 1;
            threads = (void *)uac_mem_malloc_my(*(int *)(puVar1 + 0x1294) * 0x30,0x1250);
            if (threads == (void *)0x0) {
              if (radius_err_switch != 0) {
                uVar8 = 0x1253;
                pcVar6 = "[RADIUS_ERR]%s()/%d Create radius threads structure error\n";
LAB_004458a4:
                printf(pcVar6,"_radius_thread_init",uVar8);
              }
            }
            else {
              memset(threads,0,*(int *)(PTR_DAT_007591ac + 0x1294) * 0x30);
              for (iVar2 = 0; iVar2 < *(int *)(puVar1 + 0x1294); iVar2 = iVar2 + 1) {
                iVar10 = iVar2 * 0x30;
                sprintf(acStack_6c,"%s%d","/radius_msg",iVar2);
                iVar4 = g_max_session;
                if (g_max_session < 0) {
                  iVar4 = g_max_session + 7;
                }
                piVar9 = (int *)((int)threads + iVar10);
                iVar4 = uac_msgQ_create(acStack_6c,iVar4 >> 3,0x5d0,4);
                *piVar9 = iVar4;
                if (iVar4 == -1) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x125d;
                  pcVar6 = "[RADIUS_ERR]%s()/%d Create msgq error\n";
                  goto LAB_004458a4;
                }
                iVar4 = pipe((int *)((int)threads + iVar10 + 4));
                if (iVar4 != 0) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x1263;
                  pcVar6 = "[RADIUS_ERR]%s()/%d Create msgq error\n";
                  goto LAB_004458a4;
                }
                fcntl(*(int *)((int)threads + iVar10 + 8),4,0x80);
                fcntl(*(int *)((int)threads + iVar10 + 4),4,0x80);
                pvVar7 = threads;
                uVar8 = uac_mutex_create(acStack_6c,1);
                *(undefined4 *)((int)pvVar7 + iVar10 + 0xc) = uVar8;
                pvVar7 = threads;
                if (*(int *)((int)threads + iVar10 + 0xc) == 0) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x126d;
                  pcVar6 = "[RADIUS_ERR]%s()/%d Create mutex error\n";
                  goto LAB_004458a4;
                }
                uVar8 = uac_mem_malloc_my(0x7fe,0x1271);
                *(undefined4 *)((int)pvVar7 + iVar10 + 0x10) = uVar8;
                pvVar7 = *(void **)((int)threads + iVar10 + 0x10);
                if (pvVar7 == (void *)0x0) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x1274;
                  pcVar6 = "[RADIUS_ERR]%s()/%d Malloc send_buf error\n";
                  goto LAB_004458a4;
                }
                memset(pvVar7,0,0x7fe);
                pvVar7 = threads;
                uVar8 = uac_mem_malloc_my(0xc,0x127a);
                *(undefined4 *)((int)pvVar7 + iVar10 + 0x14) = uVar8;
                pvVar7 = threads;
                if (*(int *)((int)threads + iVar10 + 0x14) == 0) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x127d;
                  pcVar6 = "[RADIUS_ERR]%s()/%d Malloc free_head error\n";
                  goto LAB_004458a4;
                }
                uVar8 = uac_mem_malloc_my(0xc,0x1281);
                *(undefined4 *)((int)pvVar7 + iVar10 + 0x18) = uVar8;
                pvVar7 = threads;
                if (*(int *)((int)threads + iVar10 + 0x18) == 0) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x1284;
                  pcVar6 = "[RADIUS_ERR]%s()/%d Malloc timer_head error\n";
                  goto LAB_004458a4;
                }
                uVar8 = uac_mem_malloc_my(0xc,0x1288);
                *(undefined4 *)((int)pvVar7 + iVar10 + 0x1c) = uVar8;
                if (*(int *)((int)threads + iVar10 + 0x1c) == 0) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x128b;
                  pcVar6 = "[RADIUS_ERR]%s()/%d Malloc check_head error\n";
                  goto LAB_004458a4;
                }
                iVar4 = 0;
                uac_list_init(*(undefined4 *)((int)threads + iVar10 + 0x14));
                uac_list_init(*(undefined4 *)((int)threads + iVar10 + 0x18));
                uac_list_init(*(undefined4 *)((int)threads + iVar10 + 0x1c));
                do {
                  pvVar7 = (void *)uac_mem_malloc_my(0x648,0x1296);
                  if (pvVar7 == (void *)0x0) {
                    if (radius_err_switch != 0) {
                      printf("[RADIUS_ERR]%s()/%d Malloc node error %d\n","_radius_thread_init",
                             0x1299,iVar4);
                    }
                    goto LAB_0044580c;
                  }
                  memset(pvVar7,0,0x648);
                  iVar4 = iVar4 + 1;
                  uac_list_insert_first
                            (*(undefined4 *)((int)threads + iVar10 + 0x14),(int)pvVar7 + 0x570);
                } while (iVar4 != 0x40);
                iVar4 = socket(2,1,0);
                if (iVar4 < 0) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x12a6;
                  pcVar6 = "[RADIUS_ERR]%s()/%d Create radius socket error\n\n";
                  goto LAB_004458a4;
                }
                local_78 = 0x800;
                iVar5 = setsockopt(iVar4,0xffff,0x1002,&local_78,4);
                if (iVar5 == -1) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x12b6;
                  pcVar6 = "[RADIUS_ERR]%s()/%d setsockopt radius socket SO_RCVBUF error\n\n";
                  goto LAB_004458a4;
                }
                local_78 = 0x100000;
                iVar5 = setsockopt(iVar4,0xffff,0x1001,&local_78,4);
                if (iVar5 == -1) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x12bd;
                  pcVar6 = "[RADIUS_ERR]%s()/%d setsockopt radius socket SO_SNDBUF error\n\n";
                  goto LAB_004458a4;
                }
                *(int *)((int)threads + iVar10 + 0x20) = iVar4;
                iVar4 = socket(10,1,0);
                if (iVar4 < 0) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x12c9;
                  pcVar6 = "[RADIUS_ERR]%s()/%d Create radius socket error\n\n";
                  goto LAB_004458a4;
                }
                local_78 = 0x800;
                iVar5 = setsockopt(iVar4,0xffff,0x1002,&local_78,4);
                if (iVar5 == -1) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x12d9;
                  pcVar6 = "[RADIUS_ERR]%s()/%d setsockopt radius socket SO_RCVBUF error\n\n";
                  goto LAB_004458a4;
                }
                local_78 = 0x100000;
                iVar5 = setsockopt(iVar4,0xffff,0x1001,&local_78,4);
                pvVar7 = threads;
                if (iVar5 == -1) {
                  if (radius_err_switch == 0) goto LAB_0044580c;
                  uVar8 = 0x12e0;
                  pcVar6 = "[RADIUS_ERR]%s()/%d setsockopt radius socket SO_SNDBUF error\n\n";
                  goto LAB_004458a4;
                }
                *(int *)((int)threads + iVar10 + 0x24) = iVar4;
                uVar11 = uac_time_usecs();
                *(undefined8 *)((int)pvVar7 + iVar10 + 0x28) = uVar11;
              }
              iVar2 = 0;
              if (threads != (void *)0x0) {
                for (; iVar2 < *(int *)(puVar1 + 0x1294); iVar2 = iVar2 + 1) {
                  sprintf(acStack_4c,"radius%d",iVar2);
                  piVar9 = (int *)uac_mem_malloc_my(4,0x1343);
                  if (piVar9 != (int *)0x0) {
                    *piVar9 = iVar2;
                    iVar4 = uac_thread_create(&g_radius_thread,acStack_4c,_radius_thread,piVar9);
                    if (iVar4 != 0) {
                      if (radius_err_switch == 0) {
                        return 0xffffffff;
                      }
                      uVar8 = 0x134c;
                      pcVar6 = "[RADIUS_ERR]%s()/%d Create worker thread error\n";
                      goto LAB_004453a8;
                    }
                  }
                }
                iVar2 = jcs_callback_register("radius",0,_radius_jcs_add_callback);
                if (iVar2 == 0) {
                  local_78 = 0;
                  iVar2 = uac_thread_create(&local_78,"radius_dae",_radius_dae_recv,rh);
                  if (iVar2 == 0) {
                    return 0;
                  }
                  if (radius_err_switch != 0) {
                    printf("[RADIUS_ERR]%s()/%d Create dae thread error\n","_radius_dae_thread",
                           0x1232);
                  }
                  if (radius_err_switch == 0) {
                    return 0xffffffff;
                  }
                  printf("[RADIUS_ERR]%s()/%d JCS register error!\n","radius_init",0x135f);
                  return 0xffffffff;
                }
                if (radius_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar8 = 0x1357;
                pcVar6 = "[RADIUS_ERR]%s()/%d JCS register error!\n";
                goto LAB_004453a8;
              }
            }
LAB_0044580c:
            if (radius_err_switch == 0) {
              return 0xffffffff;
            }
            uVar8 = 0x133a;
            pcVar6 = "[RADIUS_ERR]%s()/%d Create thread para\n";
          }
        }
        else {
          if (radius_err_switch == 0) {
            return 0xffffffff;
          }
          uVar8 = 0x1326;
          pcVar6 = "[RADIUS_ERR]%s()/%d read mac addr failed\n";
        }
      }
      else {
        if (radius_err_switch == 0) {
          return 0xffffffff;
        }
        uVar8 = 0x131a;
        pcVar6 = "[RADIUS_ERR]%s()/%d Error reading radius dictionary\n";
      }
    }
    else {
      if (radius_err_switch == 0) {
        return 0xffffffff;
      }
      uVar8 = 0x1314;
      pcVar6 = "[RADIUS_ERR]%s()/%d Error init radius dictionary\n";
    }
  }
LAB_004453a8:
  printf(pcVar6,"radius_init",uVar8);
  return 0xffffffff;
}

