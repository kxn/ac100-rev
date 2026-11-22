// func wportal_thread_update_rdt_ftt_to_ap @ 0040c608 size=2140

void wportal_thread_update_rdt_ftt_to_ap(void)

{
  int iVar1;
  uint *puVar2;
  undefined2 uVar5;
  uint *__s;
  uint uVar3;
  uint uVar4;
  char cVar6;
  undefined1 uVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  size_t sVar11;
  undefined1 *puVar12;
  uint uVar13;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 auStack_44 [8];
  int local_3c;
  int local_30;
  
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  FUN_0051ad88(&local_50);
  do {
    FUN_004082d0(wportal_update_rdt_ftt_mutex,0xffffffff);
    while (iVar1 = FUN_004081b0(&g_wportal_update_rdt_ftt_list), iVar1 == 0) {
      FUN_004086c0(wportal_update_rdt_ftt_cond,wportal_update_rdt_ftt_mutex,0xffffffff);
    }
    FUN_004082c0(&local_50,&g_wportal_update_rdt_ftt_list);
    FUN_00407f30(wportal_update_rdt_ftt_mutex);
    while (iVar1 = FUN_004081b0(&local_50), iVar1 != 0) {
      FUN_00408500(iVar1);
      iVar10 = *(int *)(iVar1 + 0xc);
      if (iVar10 == 1) {
        puVar9 = *(uint **)(iVar1 + 0x10);
        uVar13 = *puVar9;
        iVar10 = _wportal_db_support_new_portal_by_id(uVar13);
        if (iVar10 == 0) {
          puVar2 = (uint *)FUN_00408450(0x9c,0x366);
          if (puVar2 != (uint *)0x0) {
            memset(puVar2,0,0x9c);
            puVar2[3] = 1;
            sVar11 = 0x9c;
            *puVar2 = puVar9[1];
            memcpy(puVar2 + 6,(void *)puVar9[3],0x84);
            uVar4 = puVar2[6];
            if (uVar4 == 0) {
              uVar4 = 0xfff;
            }
            puVar2[6] = uVar4;
            goto LAB_0040c7c8;
          }
        }
        else {
          cVar6 = *(char *)(puVar9[4] + 0x84);
          sVar11 = 0x9b;
          if (0 < cVar6) {
            sVar11 = cVar6 * 2 + 0x9b;
          }
          puVar2 = (uint *)FUN_00408450(sVar11,0x342);
          if (puVar2 != (uint *)0x0) {
            memset(puVar2,0,sVar11);
            puVar2[3] = 1;
            *puVar2 = puVar9[2];
            uVar5 = 0xfff;
            if (*(int *)puVar9[4] != 0) {
              uVar5 = (short)*(int *)puVar9[4];
            }
            *(undefined2 *)(puVar2 + 6) = uVar5;
            memcpy((void *)((int)puVar2 + 0x1a),(void *)(puVar9[4] + 4),0x80);
            *(char *)((int)puVar2 + 0x9a) = cVar6;
            puVar12 = (undefined1 *)((int)puVar2 + 0x9b);
            iVar10 = FUN_004081b0(puVar9[4] + 0x88);
            if (iVar10 != 0) {
              uVar7 = *(undefined1 *)(iVar10 + 0xc);
              while( true ) {
                *puVar12 = uVar7;
                puVar12[1] = *(undefined1 *)(iVar10 + 0xd);
                puVar12 = puVar12 + 2;
                iVar10 = FUN_00408680(iVar10);
                if (iVar10 == 0) break;
                uVar7 = *(undefined1 *)(iVar10 + 0xc);
              }
            }
LAB_0040c7c8:
            serv_wtp_address_arg_init(auStack_44);
            apmngr_db_get_addr_by_capacity(uVar13 & 0xffff,auStack_44,1,1,0x15f0000,0);
            _wportal_update_to_ap_handle(puVar2,sVar11,auStack_44,1);
            FUN_00407df0(puVar2);
            serv_wtp_address_arg_destroy(auStack_44);
          }
        }
        if (puVar9[3] == 0) {
          uVar13 = puVar9[4];
        }
        else {
          FUN_00407df0();
          uVar13 = puVar9[4];
        }
        if (uVar13 == 0) {
          iVar10 = *(int *)(iVar1 + 0x10);
        }
        else {
          uVar13 = puVar9[4];
          while (iVar10 = FUN_004081b0(uVar13 + 0x88), iVar10 != 0) {
            FUN_00408500(iVar10);
            FUN_00407df0(iVar10);
            uVar13 = puVar9[4];
          }
          uVar13 = puVar9[4];
LAB_0040c864:
          FUN_00407df0(uVar13);
          iVar10 = *(int *)(iVar1 + 0x10);
        }
LAB_0040c870:
        if (iVar10 != 0) {
          FUN_00407df0();
        }
      }
      else {
        if (iVar10 == 2) {
          puVar9 = *(uint **)(iVar1 + 0x10);
          sVar11 = 0xb4;
          uVar13 = puVar9[1];
          uVar4 = *puVar9;
          if ((*(int *)(uVar13 + 0x98) == 1) || (sVar11 = 0xc0, *(int *)(uVar13 + 0x98) == 2)) {
            puVar2 = (uint *)FUN_00408450(sVar11,0x3f6);
            if (puVar2 == (uint *)0x0) {
              if (wportal_err_switch == 0) {
                uVar13 = puVar9[1];
              }
              else {
                iVar10 = is_target_debug_ap();
                if (iVar10 == 0) {
                  uVar13 = puVar9[1];
                }
                else {
                  printf("[WPORTAL_ERR]%s()/%d malloc error\n",
                         "_wportal_update_free_strategy_cb_handle",0x3f9);
                  uVar13 = puVar9[1];
                }
              }
            }
            else {
              memset(puVar2,0,sVar11);
              __s = (uint *)FUN_00408450(0x4c,0x3ff);
              if (__s == (uint *)0x0) {
                if ((wportal_err_switch != 0) && (iVar10 = is_target_debug_ap(puVar2), iVar10 != 0))
                {
                  printf("[WPORTAL_ERR]%s()/%d malloc error\n",
                         "_wportal_update_free_strategy_cb_handle",0x402);
                }
              }
              else {
                memset(__s,0,0x4c);
                puVar2[5] = 1;
                *puVar2 = puVar9[2];
                __s[5] = 1;
                *__s = puVar9[2];
                if (*(int *)(uVar13 + 0x98) == 1) {
                  if (wportal_info_switch == 0) {
                    uVar3 = *(uint *)(uVar13 + 0x9c);
                  }
                  else {
                    iVar10 = is_target_debug_ap();
                    if (iVar10 == 0) {
                      uVar3 = *(uint *)(uVar13 + 0x9c);
                    }
                    else {
                      printf("[WPORTAL_INFO]%s()/%d send ftt to ap IPv4\n",
                             "_wportal_update_free_strategy_cb_handle",0x413);
                      uVar3 = *(uint *)(uVar13 + 0x9c);
                    }
                  }
                  puVar2[6] = uVar3;
                  *(undefined1 *)(puVar2 + 7) = *(undefined1 *)(uVar13 + 0xa0);
                  if (wportal_info_switch == 0) {
                    cVar6 = *(char *)(puVar2 + 7);
                  }
                  else {
                    iVar10 = is_target_debug_ap();
                    if (iVar10 == 0) {
                      cVar6 = *(char *)(puVar2 + 7);
                    }
                    else {
                      printf("[WPORTAL_INFO]%s()/%d send ftt to ap IPv4 match_type is %d\n",
                             "_wportal_update_free_strategy_cb_handle",0x418,
                             (uint)*(byte *)(puVar2 + 7));
                      cVar6 = *(char *)(puVar2 + 7);
                    }
                  }
                  if (cVar6 == '\0') {
                    puVar2[0xd] = *(uint *)(uVar13 + 0xb8);
                    puVar2[0xe] = *(uint *)(uVar13 + 0xbc);
                    puVar2[0x12] = *(uint *)(uVar13 + 0xcc);
                    puVar2[0x11] = *(uint *)(uVar13 + 200);
                    puVar2[0x13] = *(uint *)(uVar13 + 0xd0);
                    puVar2[8] = *(uint *)(uVar13 + 0xa4);
                    puVar2[9] = *(uint *)(uVar13 + 0xa8);
                    memcpy(puVar2 + 0xb,(void *)(uVar13 + 0xb0),6);
                    puVar2[0x10] = *(uint *)(uVar13 + 0xc4);
                    puVar2[0xf] = *(uint *)(uVar13 + 0xc0);
                    puVar2[10] = *(uint *)(uVar13 + 0xac);
                    cVar6 = *(char *)(uVar13 + 0xa0);
                  }
                  else {
                    puVar2[8] = *(uint *)(uVar13 + 0xa4);
                    puVar2[9] = *(uint *)(uVar13 + 0xa8);
                    puVar2[10] = *(uint *)(uVar13 + 0xac);
                    memcpy(puVar2 + 0xb,(void *)(uVar13 + 0xb0),6);
                    memcpy((void *)((int)puVar2 + 0x32),(void *)(uVar13 + 0xb6),0x80);
                    cVar6 = *(char *)(uVar13 + 0xa0);
                  }
                  if (cVar6 == '\0') {
                    __s[6] = *(uint *)(uVar13 + 0x9c);
                    __s[7] = *(uint *)(uVar13 + 0xa4);
                    __s[8] = *(uint *)(uVar13 + 0xa8);
                    __s[9] = *(uint *)(uVar13 + 0xac);
                    memcpy(__s + 10,(void *)(uVar13 + 0xb0),6);
                    __s[0xc] = *(uint *)(uVar13 + 0xb8);
                    __s[0xd] = *(uint *)(uVar13 + 0xbc);
                    __s[0xe] = *(uint *)(uVar13 + 0xc0);
                    __s[0xf] = *(uint *)(uVar13 + 0xc4);
                    __s[0x10] = *(uint *)(uVar13 + 200);
                    __s[0x11] = *(uint *)(uVar13 + 0xcc);
                    __s[0x12] = *(uint *)(uVar13 + 0xd0);
                  }
                }
                else {
                  if (wportal_info_switch == 0) {
                    uVar3 = *(uint *)(uVar13 + 0x9c);
                  }
                  else {
                    iVar10 = is_target_debug_ap();
                    if (iVar10 == 0) {
                      uVar3 = *(uint *)(uVar13 + 0x9c);
                    }
                    else {
                      printf("[WPORTAL_INFO]%s()/%d send ftt to ap IPv6\n",
                             "_wportal_update_free_strategy_cb_handle",0x443);
                      uVar3 = *(uint *)(uVar13 + 0x9c);
                    }
                  }
                  puVar2[6] = uVar3;
                  *(undefined1 *)(puVar2 + 7) = *(undefined1 *)(uVar13 + 0xa0);
                  if (wportal_info_switch == 0) {
                    uVar3 = (uint)*(byte *)(puVar2 + 7);
                  }
                  else {
                    iVar10 = is_target_debug_ap();
                    uVar3 = (uint)*(byte *)(puVar2 + 7);
                    if (iVar10 != 0) {
                      printf("[WPORTAL_INFO]%s()/%d ID[%d]send ftt to ap IPv6 match_type is %d\n",
                             "_wportal_update_free_strategy_cb_handle",0x448,puVar2[6],uVar3);
                      uVar3 = (uint)*(byte *)(puVar2 + 7);
                    }
                  }
                  if (uVar3 == 0) {
                    memcpy((void *)((int)puVar2 + 0x3e),(void *)(uVar13 + 0xc2),0x10);
                    puVar2[0x14] = *(uint *)(uVar13 + 0xd4);
                    puVar2[0x18] = *(uint *)(uVar13 + 0xe4);
                    puVar2[0x17] = *(uint *)(uVar13 + 0xe0);
                    puVar2[0x19] = *(uint *)(uVar13 + 0xe8);
                    memcpy(puVar2 + 8,(void *)(uVar13 + 0xa4),0x10);
                    puVar2[0xc] = *(uint *)(uVar13 + 0xb4);
                    memcpy(puVar2 + 0xe,(void *)(uVar13 + 0xbc),6);
                    puVar2[0x16] = *(uint *)(uVar13 + 0xdc);
                    puVar2[0x15] = *(uint *)(uVar13 + 0xd8);
                    puVar2[0xd] = *(uint *)(uVar13 + 0xb8);
                  }
                  else {
                    memcpy(puVar2 + 8,(void *)(uVar13 + 0xa4),0x10);
                    puVar2[0xc] = *(uint *)(uVar13 + 0xb4);
                    puVar2[0xd] = *(uint *)(uVar13 + 0xb8);
                    memcpy(puVar2 + 0xe,(void *)(uVar13 + 0xbc),6);
                    memcpy((void *)((int)puVar2 + 0x3e),(void *)(uVar13 + 0xc2),0x80);
                  }
                }
                serv_wtp_address_arg_init(auStack_44);
                local_30 = *(int *)(uVar13 + 0x98);
                puVar8 = puVar2;
                if (local_30 == 1) {
                  uVar4 = uVar4 & 0xffff;
                  apmngr_db_get_addr_by_capacity(uVar4,auStack_44,1,1,0x15f0000,1,2);
                  if (local_3c == 0) {
                    if (*(char *)(uVar13 + 0xa0) != '\0') goto LAB_0040ca68;
                    apmngr_db_get_addr_by_capacity(uVar4,auStack_44,0,1,0x15f0000,local_30,2);
                    sVar11 = 0x4c;
                    puVar8 = __s;
                  }
LAB_0040cd40:
                  _wportal_update_to_ap_handle(puVar8,sVar11,auStack_44,1);
                }
                else if ((local_30 == 2) &&
                        (apmngr_db_get_addr_by_capacity
                                   (uVar4 & 0xffff,auStack_44,1,1,0x15f0000,1,0x21), local_3c != 0))
                goto LAB_0040cd40;
LAB_0040ca68:
                serv_wtp_address_arg_destroy(auStack_44);
                FUN_00407df0(puVar2);
                puVar2 = __s;
              }
              FUN_00407df0(puVar2);
              uVar13 = puVar9[1];
            }
          }
          else if (wportal_err_switch == 0) {
            uVar13 = puVar9[1];
          }
          else {
            iVar10 = is_target_debug_ap();
            if (iVar10 == 0) {
              uVar13 = puVar9[1];
            }
            else {
              printf("[WPORTAL_ERR]%s()/%d Free strategy entry type %d is not allowed.\n",
                     "_wportal_update_free_strategy_cb_handle",0x3f0,*(undefined4 *)(uVar13 + 0x98))
              ;
              uVar13 = puVar9[1];
            }
          }
          if (uVar13 != 0) goto LAB_0040c864;
          iVar10 = *(int *)(iVar1 + 0x10);
          goto LAB_0040c870;
        }
        if (iVar10 == 3) {
          puVar9 = *(uint **)(iVar1 + 0x10);
          _wportal_update_to_ap_handle(*puVar9,puVar9[1],puVar9 + 2,puVar9[6]);
          serv_wtp_address_arg_destroy(puVar9 + 2);
          uVar13 = *puVar9;
          if (uVar13 != 0) goto LAB_0040c864;
          iVar10 = *(int *)(iVar1 + 0x10);
          goto LAB_0040c870;
        }
      }
      FUN_00407df0(iVar1);
    }
  } while( true );
}

