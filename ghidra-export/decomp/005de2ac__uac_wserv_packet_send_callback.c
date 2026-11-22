// func _uac_wserv_packet_send_callback @ 005de2ac size=7412

undefined4 _uac_wserv_packet_send_callback(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  size_t sVar8;
  char *pcVar9;
  void *pvVar10;
  uint uVar11;
  char cVar14;
  byte *pbVar12;
  char cVar15;
  char *pcVar13;
  undefined1 uVar16;
  uint uVar17;
  size_t sVar18;
  undefined1 *puVar19;
  undefined4 uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  char cVar24;
  byte local_690 [4];
  byte local_68c;
  char cStack_68b;
  char local_68a;
  byte local_688;
  char cStack_687;
  undefined2 uStack_686;
  undefined2 local_684;
  ushort uStack_682;
  char *local_680;
  undefined4 local_67c;
  undefined4 local_678;
  undefined4 local_674;
  undefined4 local_670;
  undefined4 local_66c;
  uint local_668;
  byte *local_664;
  undefined4 local_660;
  undefined4 local_65c;
  undefined4 local_658;
  undefined4 local_654;
  uint local_650;
  undefined4 local_64c;
  undefined4 local_648;
  undefined4 local_644;
  undefined4 local_640;
  undefined4 local_63c;
  undefined4 local_638;
  undefined4 local_634;
  undefined4 local_630;
  undefined2 local_62c;
  undefined2 uStack_62a;
  undefined2 local_628;
  undefined1 uStack_626;
  byte bStack_625;
  byte *local_624;
  byte local_620;
  char local_61f;
  uint local_61e;
  undefined1 local_61a;
  undefined4 local_619;
  undefined4 local_615;
  undefined4 uStack_611;
  undefined1 uStack_60d;
  uint local_60c;
  undefined1 auStack_608 [4];
  undefined3 uStack_604;
  byte local_600;
  char local_5ff;
  undefined2 local_5fe;
  undefined1 local_5fc;
  undefined1 local_5fb;
  undefined2 local_5fa;
  undefined4 local_5f4;
  undefined2 local_5f0;
  undefined1 local_5ee;
  undefined1 local_5ed;
  undefined1 local_5ec;
  undefined1 local_5eb;
  undefined2 local_5e8;
  void *local_5e4;
  char acStack_5e0 [32];
  undefined1 local_5c0;
  byte local_5bc;
  char local_5bb;
  uint local_5ba;
  undefined1 auStack_5b6 [20];
  undefined1 auStack_5a2 [20];
  undefined1 auStack_58e [20];
  undefined2 local_57a;
  undefined2 local_578;
  undefined2 local_576;
  ushort local_574;
  void *local_572;
  undefined1 auStack_56c [9];
  char local_563;
  char acStack_518 [128];
  undefined4 local_498;
  undefined1 uStack_3fa;
  char cStack_3ed;
  char *local_3ec;
  undefined1 auStack_3e8 [50];
  undefined1 local_3b6 [8];
  undefined1 local_3ae [4];
  undefined1 local_3aa [4];
  undefined4 local_3a6;
  uint local_3a2;
  char acStack_39e [40];
  undefined4 local_376;
  undefined4 local_372;
  char acStack_36e [68];
  undefined4 local_32a;
  uint local_326;
  char local_322;
  char local_321;
  undefined1 auStack_310 [16];
  ushort local_300;
  undefined4 local_2d0;
  undefined1 auStack_f8 [152];
  byte local_60;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  memset(auStack_310,0,0x2d8);
  local_67c = 0;
  local_678 = 0;
  local_674 = 0;
  memset(acStack_518,0,0x205);
  local_690[0] = 0;
  cStack_68b = '\0';
  local_68c = 0;
  local_68a = '\0';
  iVar4 = apmngr_db_entry_get_by_mac(param_1,auStack_310);
  if (iVar4 != 0) {
    if (g_wserv_warning == 0) {
      return 0;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0;
    }
    printf("<wserv>[warning]%s(): %d  -> apmngr_db_entry_get_by_mac() fail.\r\n",
           "_uac_wserv_packet_send_callback",0x5dd);
    return 0;
  }
  FUN_004082d0(DAT_007598e4,0xffffffff);
  uVar22 = (uint)local_300;
  iVar4 = apmngr_db_get_ap_max();
  if ((int)uVar22 < iVar4) {
    memcpy(&local_67c,(void *)(DAT_007598e8 + uVar22 * 0xc),0xc);
    iVar4 = (int)local_67c._0_1_;
  }
  else {
    iVar4 = (int)local_67c._0_1_;
    if (g_wserv_warning != 0) {
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        iVar4 = (int)local_67c._0_1_;
      }
      else {
        printf("<wserv>[warning]%s(): %d  -> ap_id[%d] is invalid!\r\n",
               "_uac_wserv_packet_get_by_ap_id",0x138,uVar22);
        iVar4 = (int)local_67c._0_1_;
      }
    }
  }
  if (((iVar4 == -1) || (local_67c._1_1_ == -1)) && ((char)local_67c == '\0')) {
    if ((g_wserv_debug != 0) && (iVar4 = is_target_debug_ap(local_300), iVar4 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> no packet to send\r\n","_uac_wserv_packet_send_callback",
             0x5e4);
    }
  }
  else {
    if (local_678._0_1_ == '\x01') {
      if ((g_wserv_debug != 0) && (iVar4 = is_target_debug_ap(local_300), iVar4 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> need to send at last\r\n",
               "_uac_wserv_packet_send_callback",0x5eb);
      }
      _uac_wserv_packet_last_send_status_set_by_ap_id(local_300,0);
      FUN_00407f30(DAT_007598e4);
      return 3;
    }
    if ((iVar4 != -1) && (local_67c._1_1_ != -1)) {
      _uac_wserv_packet_type_get_by_wlan_id(local_300,iVar4,local_67c._1_1_,local_690);
      pcVar5 = (char *)rdmngr_db_generate_rd_id(local_300,local_67c._0_1_ + 1);
      cVar24 = local_67c._1_1_ + '\x01';
      bVar2 = (byte)pcVar5;
      if ((local_690[0] & 0xf) != 1) {
        if (1 < (local_690[0] & 0xf) - 2) goto LAB_005de560;
        iVar4 = cw_user_send_pkt_node_create(1,0);
        if (iVar4 == 0) goto LAB_005de5f8;
        iVar23 = *(int *)(iVar4 + 0xc);
        local_688 = 0;
        cStack_687 = '\0';
        iVar6 = cw_parsed_pkt_create(0x33dd01);
        if (iVar6 == 0) {
          if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
            printf("<wserv>[error]%s(): %d  -> no memory!\r\n","_uac_wserv_del_packet_create",0x341)
            ;
          }
        }
        else {
          local_688 = bVar2 & 0xf;
          cStack_687 = cVar24;
          iVar7 = cw_service_msg_add(iVar6,0x403,&local_688,0);
          if (iVar7 == 0) {
            iVar23 = capwap_packet_assemble(iVar23 + 0x10,iVar6);
            if (iVar23 != -1) {
              cw_parsed_pkt_destroy(iVar6);
              FUN_004086b0(param_2,iVar4);
              _uac_wserv_packet_type_set_by_wlan_id
                        (local_300,(int)local_67c._0_1_,local_67c._1_1_,
                         (local_690[0] & 0xf) != 2 | 0x20);
              _uac_wserv_packet_next_cur_id_update_by_ap_id(local_300);
              goto LAB_005de560;
            }
            if ((g_wserv_error != 0) && (iVar23 = is_target_debug_ap(), iVar23 != 0)) {
              pcVar5 = "<wserv>[error]%s(): %d  -> capwap_packet_assemble() fail!\r\n";
              uVar20 = 0x354;
              goto LAB_005de840;
            }
          }
          else if ((g_wserv_error != 0) && (iVar23 = is_target_debug_ap(), iVar23 != 0)) {
            pcVar5 = "<wserv>[error]%s(): %d  -> cw_service_msg_add() fail!\r\n";
            uVar20 = 0x34d;
LAB_005de840:
            printf(pcVar5,"_uac_wserv_del_packet_create",uVar20);
          }
          cw_parsed_pkt_destroy(iVar6);
        }
        if (g_wserv_warning == 0) {
          iVar6 = *(int *)(iVar4 + 0xc);
        }
        else {
          iVar6 = is_target_debug_ap();
          if (iVar6 == 0) {
            iVar6 = *(int *)(iVar4 + 0xc);
          }
          else {
            printf("<wserv>[warning]%s(): %d  -> _uac_wserv_del_packet_create() fail.\r\n",
                   "_uac_wserv_packet_send_callback",0x656);
            iVar6 = *(int *)(iVar4 + 0xc);
          }
        }
        *(undefined4 *)(iVar6 + 8) = 1;
        goto LAB_005de5f8;
      }
      iVar4 = wserv_db_rd_get_wserv_id(pcVar5,cVar24);
      if (iVar4 == -1) {
        iVar4 = (int)local_67c._0_1_;
        if (g_wserv_warning == 0) goto LAB_005de6b8;
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = (int)local_67c._0_1_;
          goto LAB_005de6b8;
        }
        pcVar5 = "<wserv>[warning]%s(): %d  -> uac_wservice_get_wserv_id() fail.\r\n";
        uVar20 = 0x5fc;
      }
      else {
        iVar4 = wserv_db_get_entry_by_id(iVar4,acStack_518);
        if (iVar4 == 0) {
          iVar4 = cw_user_send_pkt_node_create(1,0);
          if (iVar4 == 0) goto LAB_005de5f8;
          iVar6 = rdmngr_db_get_rd_freq_band(pcVar5);
          if (iVar6 == -1) {
            if ((g_wserv_warning != 0) && (iVar6 = is_target_debug_ap(DAT_007598e4), iVar6 != 0)) {
              printf("<wserv>[warning]%s(): %d  -> rdmngr_db_get_rd_freq_band() or apdb_get_radio_by_id() fail.\r\n"
                     ,"_uac_wserv_packet_send_callback",0x60d);
            }
            goto LAB_005de5f8;
          }
          local_38 = *(int *)(iVar4 + 0xc);
          local_34 = apmngr_db_capacity_support(local_300,1,0x11);
          local_30 = apmngr_db_capacity_support(local_300,1,0x20);
          iVar6 = apdb_support_wpa3_by_id(local_2d0,auStack_f8,local_67c._0_1_ + '\x01',iVar6);
          local_2c = apmngr_db_capacity_support(local_300,1,0x3f);
          memset(acStack_5e0,0,0x21);
          memset(auStack_56c,0,0x54);
          memset(&local_600,0,0x20);
          local_670 = 0;
          local_66c = 0;
          local_668 = 0;
          local_664 = (byte *)((uint)local_664 & 0xffffff);
          local_65c = 0;
          local_658 = 0;
          local_654 = 0;
          local_650 = local_650 & 0xffffff;
          local_634 = 0;
          local_630 = 0;
          local_62c = 0;
          uStack_62a = 0;
          local_628 = 0;
          uStack_626 = 0;
          bStack_625 = 0;
          local_624 = (byte *)0x0;
          memset(&local_620,0,0x1f);
          memset(&local_5bc,0,0x4e);
          local_688 = 0;
          cStack_687 = '\0';
          uStack_686 = 0;
          uVar17 = 0x33dd01;
          local_684 = 0;
          uStack_682 = 0;
          local_680 = (char *)0x0;
          local_648 = 0;
          local_644 = 0;
          local_640 = 0;
          local_63c = 0;
          local_638 = 0;
          uVar22 = cw_parsed_pkt_create();
          if (uVar22 == 0) {
            iVar23 = -1;
            if (g_wserv_error != 0) {
              iVar6 = is_target_debug_ap();
              if (iVar6 == 0) {
                uVar21 = (uint)(auStack_608 + 3) & 3;
                uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                         uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                goto LAB_005deaac;
              }
              pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
              uVar20 = 0x411;
              goto LAB_005dec70;
            }
LAB_005deaa8:
            uVar17 = CONCAT13(auStack_608[3],uStack_604);
          }
          else {
            if (local_3ec == (char *)0x2) {
              puVar19 = auStack_3e8;
              iVar23 = wserv_db_ssid_utf8_to_gbk(puVar19,acStack_5e0);
              if (iVar23 == 0) {
                if ((g_wserv_debug != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
                  printf("<wserv>[debug]%s(): %d  -> wserv_db_ssid_utf8_to_gbk() %s->%s!\r\n",
                         "_uac_wserv_add_packet_create",0x41d,auStack_3e8,acStack_5e0);
                }
                goto LAB_005deb8c;
              }
              uVar17 = (uint)(auStack_608 + 3) & 3;
              uVar17 = *(int *)(auStack_608 + 3 + -uVar17) << uVar17 * 8 |
                       (uint)puVar19 & 0xffffffffU >> (4 - uVar17) * 8;
              if (g_wserv_error != 0) {
                iVar6 = is_target_debug_ap();
                if (iVar6 != 0) {
                  pcVar5 = "<wserv>[error]%s(): %d  -> wserv_db_ssid_utf8_to_gbk() fail!\r\n";
                  uVar20 = 0x41a;
                  goto LAB_005dec70;
                }
                uVar21 = (uint)(auStack_608 + 3) & 3;
                uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                         uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
              }
              goto LAB_005deaac;
            }
            if (local_3ec == (char *)0x1) {
              iVar23 = -1;
              memcpy(acStack_5e0,auStack_3e8,0x21);
LAB_005deb8c:
              local_5c0 = 0;
              sVar8 = strlen(acStack_5e0);
              local_5fc = 0;
              local_5fa = 0;
              if (0x1f < (int)sVar8) {
                sVar8 = 0x20;
              }
              local_5eb = 1;
              local_5fb = 0;
              local_5f4 = 0;
              local_5f0 = 0;
              local_5ee = 0;
              local_5ed = 0;
              local_5ec = 0;
              local_5fe = 0x8000;
              local_5e8 = (undefined2)sVar8;
              sVar18 = sVar8;
              local_600 = bVar2 & 0xf;
              local_5ff = cVar24;
              local_5e4 = (void *)FUN_00408450(sVar8,0x43e);
              if (local_5e4 == (void *)0x0) {
                uVar17 = (uint)(auStack_608 + 3) & 3;
                uVar17 = *(int *)(auStack_608 + 3 + -uVar17) << uVar17 * 8 |
                         sVar18 & 0xffffffffU >> (4 - uVar17) * 8;
                if (g_wserv_error != 0) {
                  iVar6 = is_target_debug_ap();
                  if (iVar6 != 0) {
                    pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                    uVar20 = 0x441;
LAB_005dec70:
                    printf(pcVar5,"_uac_wserv_add_packet_create",uVar20);
                    goto LAB_005dec78;
                  }
                  uVar21 = (uint)(auStack_608 + 3) & 3;
                  uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                           uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                }
              }
              else {
                if ((g_wserv_debug != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
                  printf("<wserv>[debug]%s(): %d  -> send ssid(%s), len=%d to ap!\r\n",
                         "_uac_wserv_add_packet_create",0x444,acStack_5e0,sVar8);
                }
                memcpy(local_5e4,acStack_5e0,sVar8);
                uVar21 = 0;
                uVar17 = uVar22;
                iVar7 = cw_service_msg_add(uVar22,0x400,&local_600,0);
                if (iVar7 != 0) {
                  uVar21 = (uint)(auStack_608 + 3) & 3;
                  uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                           uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                  if (g_wserv_error != 0) {
                    iVar6 = is_target_debug_ap();
                    if (iVar6 != 0) {
                      pcVar5 = "<wserv>[error]%s(): %d  -> cw_service_msg_add() fail!\r\n";
                      uVar20 = 0x449;
                      goto LAB_005dec70;
                    }
                    uVar21 = (uint)(auStack_608 + 3) & 3;
                    uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                             uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                  }
                  goto LAB_005deaac;
                }
                if (local_2c == 0) {
                  if (local_30 == 0) {
                    local_670 = CONCAT13(bVar2,local_670._1_3_) & 0xfffffff;
                    local_670._1_3_ = CONCAT12(cVar24,local_670._2_2_);
                    local_66c = CONCAT22(100,CONCAT11(3,local_3b6[3]));
                    pcVar9 = pcVar5;
                    uVar11 = wserv_db_rd_get_bind_vlan_by_wserv_id
                                       (pcVar5,local_498,(int)&local_670 + 2);
                    uVar17 = (uint)local_3ae & 3;
                    if (uVar11 != 0) {
                      uVar17 = (uint)(auStack_608 + 3) & 3;
                      uVar17 = *(int *)(auStack_608 + 3 + -uVar17) << uVar17 * 8 |
                               (uint)pcVar9 & 0xffffffffU >> (4 - uVar17) * 8;
                      if (g_wserv_error != 0) {
                        iVar6 = is_target_debug_ap();
                        if (iVar6 != 0) {
                          pcVar5 = 
                          "<wserv>[error]%s(): %d  -> wserv_db_rd_get_bind_vlan_by_wserv_id() fail!\r\n"
                          ;
                          uVar20 = 0x4cf;
                          goto LAB_005dec70;
                        }
                        uVar21 = (uint)(auStack_608 + 3) & 3;
                        uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                 uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                      }
                      goto LAB_005deaac;
                    }
                    uVar1 = (uint)(local_3ae + 3) & 3;
                    uVar17 = (*(int *)(local_3ae + -uVar17) << uVar17 * 8 |
                             uVar11 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar1 + 1) * 8 |
                             *(uint *)(local_3ae + 3 + -uVar1) >> (3 - uVar1) * 8;
                    local_668 = CONCAT13((char)uVar17,local_668._1_3_);
                    if (uVar17 == 2) {
                      pcVar9 = acStack_39e;
                      pcVar13 = strchr(pcVar9,0x3a);
                      if (pcVar13 != (char *)0x0) {
                        local_668 = local_668 & 0xffffff;
                        goto LAB_005df244;
                      }
                      cVar15 = local_668._0_1_;
                    }
                    else {
                      if (uVar17 == 4) {
                        cVar15 = (char)uVar17;
                        if (iVar6 != 0) goto LAB_005df248;
                        local_668 = CONCAT13(1,local_668._1_3_);
                      }
LAB_005df244:
                      cVar15 = local_668._0_1_;
                    }
LAB_005df248:
                    if (cVar15 != '\0') {
                      cVar14 = (char)local_3a6;
                      if (cVar15 == '\x01') {
LAB_005df578:
                        uVar17 = local_3a2;
                        local_688 = local_3aa[3];
                        cStack_687 = cVar14;
                        if ((local_3a6 & 0xff) == 1) {
                          uVar21 = rdmngr_db_rd_entry_get(pcVar5,auStack_56c);
                          uVar17 = (uint)&local_3a2 & 3;
                          uVar17 = *(int *)((int)&local_3a2 - uVar17) << uVar17 * 8 |
                                   uVar21 & 0xffffffffU >> (4 - uVar17) * 8;
                          if (uVar21 == 0) {
                            uVar21 = (uint)((byte)(local_563 - 3U) < 2);
                            uVar17 = (uint)&local_3a2 & 3;
                            uVar17 = *(int *)((int)&local_3a2 - uVar17) << uVar17 * 8 |
                                     uVar21 & 0xffffffffU >> (4 - uVar17) * 8;
                            if (uVar21 != 0) {
                              cStack_687 = '\x02';
                              uVar17 = local_3a2;
                            }
                          }
                        }
                        uStack_686 = (undefined2)(uVar17 >> 0x10);
                        local_684 = (undefined2)uVar17;
                        sVar8 = strlen(acStack_39e);
                        uVar17 = sVar8 & 0xffff;
                        uStack_682 = (ushort)sVar8;
                        local_680 = (char *)FUN_00408450(uVar17,0x4ea);
                        if (local_680 == (char *)0x0) {
                          uVar21 = (uint)(auStack_608 + 3) & 3;
                          uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                   uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                          if (g_wserv_error != 0) {
                            iVar6 = is_target_debug_ap();
                            if (iVar6 != 0) {
                              pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                              uVar20 = 0x4ed;
                              goto LAB_005dec70;
                            }
                            uVar21 = (uint)(auStack_608 + 3) & 3;
                            uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                     uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                          }
                          goto LAB_005deaac;
                        }
                        memcpy(local_680,acStack_39e,(uint)uStack_682);
                        pbVar12 = &local_688;
                      }
                      else {
                        uVar17 = (uint)local_3aa & 3;
                        local_3aa[3] = (byte)(*(int *)(local_3aa + -uVar17) << uVar17 * 8) |
                                       (byte)(0xffffffff >> (4 - uVar17) * 8) & 4;
                        if (cVar15 == '\x04') goto LAB_005df578;
                        uVar17 = (uint)local_3aa & 3;
                        if (cVar15 != '\x02') {
                          uVar17 = (uint)(auStack_608 + 3) & 3;
                          uVar17 = *(int *)(auStack_608 + 3 + -uVar17) << uVar17 * 8 |
                                   (uint)pcVar9 & 0xffffffffU >> (4 - uVar17) * 8;
                          if (g_wserv_error != 0) {
                            iVar6 = is_target_debug_ap();
                            if (iVar6 != 0) {
                              uVar17 = (uint)local_3ae & 3;
                              uVar17 = *(int *)(local_3ae + -uVar17) << uVar17 * 8 |
                                       uVar21 & 0xffffffffU >> (4 - uVar17) * 8;
                              uVar20 = 0x51d;
                              goto LAB_005dee70;
                            }
                            uVar21 = (uint)(auStack_608 + 3) & 3;
                            uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                     uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                          }
                          goto LAB_005deaac;
                        }
                        uVar21 = (uint)(local_3aa + 3) & 3;
                        local_620 = ((byte)(*(int *)(local_3aa + -uVar17) << uVar17 * 8) |
                                    (byte)(0xffffffff >> (4 - uVar17) * 8) & 2) &
                                    (byte)(-1 << (uVar21 + 1) * 8) |
                                    (byte)(*(uint *)(local_3aa + 3 + -uVar21) >> (3 - uVar21) * 8);
                        local_61e = local_3a2;
                        local_61f = cVar14;
                        if ((local_3a6 & 0xff) == 1) {
                          uVar21 = rdmngr_db_rd_entry_get(pcVar5,auStack_56c);
                          uVar17 = (uint)&local_3a2 & 3;
                          local_61e = *(int *)((int)&local_3a2 - uVar17) << uVar17 * 8 |
                                      uVar21 & 0xffffffffU >> (4 - uVar17) * 8;
                          if ((uVar21 == 0) && (local_61e = local_3a2, (byte)(local_563 - 3U) < 2))
                          {
                            local_61f = '\x02';
                          }
                        }
                        uVar17 = 2;
                        iVar6 = inet_pton(2,acStack_39e,&local_619);
                        if (iVar6 < 1) {
                          uVar21 = (uint)(auStack_608 + 3) & 3;
                          uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                   uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                          if (g_wserv_error != 0) {
                            iVar6 = is_target_debug_ap();
                            if (iVar6 != 0) {
                              uVar20 = 0x501;
                              goto LAB_005def1c;
                            }
                            uVar21 = (uint)(auStack_608 + 3) & 3;
                            uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                     uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                          }
                          goto LAB_005deaac;
                        }
                        uVar17 = (local_376 & 0xffff) << 0x18;
                        uStack_60d = (undefined1)((local_376 & 0xffff) >> 8);
                        local_60c = local_60c & 0xffffff | uVar17;
                        local_61a = local_34 != 0;
                        if ((bool)local_61a) {
                          local_615 = local_619;
                          uStack_611 = local_619;
                          local_372 = local_372 & 0xffff;
                          local_60c = uVar17 | local_372 << 8 | local_372 >> 8;
                          auStack_608 = (undefined1  [4])
                                        ((uint)auStack_608 & 0xffffff | local_372 << 0x18);
                        }
                        sVar8 = strlen(acStack_36e);
                        uVar17 = sVar8 & 0xffff;
                        auStack_608 = (undefined1  [4])
                                      ((uint)auStack_608 & 0xff0000ff | uVar17 << 8);
                        pvVar10 = (void *)FUN_00408450(uVar17,0x50f);
                        auStack_608[3] = (undefined1)((uint)pvVar10 >> 0x18);
                        uStack_604 = SUB43(pvVar10,0);
                        if (pvVar10 == (void *)0x0) {
                          uVar21 = (uint)(auStack_608 + 3) & 3;
                          uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                   uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                          if (g_wserv_error != 0) {
                            iVar6 = is_target_debug_ap();
                            if (iVar6 != 0) {
                              pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                              uVar20 = 0x512;
                              goto LAB_005dec70;
                            }
                            uVar21 = (uint)(auStack_608 + 3) & 3;
                            uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                     uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                          }
                          goto LAB_005deaac;
                        }
                        memcpy(pvVar10,acStack_36e,(uint)((int)auStack_608 << 8) >> 0x10);
                        pbVar12 = &local_620;
                      }
                      local_668._1_3_ = (undefined3)((uint)pbVar12 >> 8);
                      local_664._0_1_ = SUB41(pbVar12,0);
                    }
                    local_640 = 0;
                    local_63c = 0;
                    local_638 = 0;
                    local_648 = 0x12345678;
                    local_644 = 0x90000;
                    FUN_0051ad88(&local_640);
                    uVar17 = uVar22;
                    iVar6 = cw_service_msg_add(uVar22,0x25,&local_648,1,9,&local_670);
                    if (iVar6 != 0) {
                      uVar21 = (uint)(auStack_608 + 3) & 3;
                      uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                               uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                      if (g_wserv_error != 0) {
                        iVar6 = is_target_debug_ap();
                        if (iVar6 != 0) {
                          pcVar5 = "<wserv>[error]%s(): %d  -> cw_service_msg_add() fail!\r\n";
                          uVar20 = 0x52d;
                          goto LAB_005dec70;
                        }
                        uVar21 = (uint)(auStack_608 + 3) & 3;
                        uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                 uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                      }
                      goto LAB_005deaac;
                    }
                  }
                  else {
                    uVar17 = (uint)(local_3b6 + 3) & 3;
                    local_65c = CONCAT13(bVar2,local_65c._1_3_) & 0xfffffff;
                    local_65c._1_3_ = CONCAT12(cVar24,local_65c._2_2_);
                    local_658._2_2_ =
                         CONCAT11(3,local_3b6[3] & (byte)(-1 << (uVar17 + 1) * 8) |
                                    (byte)(*(uint *)(local_3b6 + 3 + -uVar17) >> (3 - uVar17) * 8));
                    local_658 = CONCAT22(100,local_658._2_2_);
                    pcVar9 = pcVar5;
                    uVar11 = wserv_db_rd_get_bind_vlan_by_wserv_id
                                       (pcVar5,local_498,(int)&local_65c + 2);
                    uVar17 = (uint)local_3ae & 3;
                    if (uVar11 != 0) {
                      uVar17 = (uint)(auStack_608 + 3) & 3;
                      uVar17 = *(int *)(auStack_608 + 3 + -uVar17) << uVar17 * 8 |
                               (uint)pcVar9 & 0xffffffffU >> (4 - uVar17) * 8;
                      if (g_wserv_error != 0) {
                        iVar6 = is_target_debug_ap();
                        if (iVar6 != 0) {
                          pcVar5 = 
                          "<wserv>[error]%s(): %d  -> wserv_db_rd_get_bind_vlan_by_wserv_id() fail!\r\n"
                          ;
                          uVar20 = 0x53c;
                          goto LAB_005dec70;
                        }
                        uVar21 = (uint)(auStack_608 + 3) & 3;
                        uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                 uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                      }
                      goto LAB_005deaac;
                    }
                    uVar1 = (uint)(local_3ae + 3) & 3;
                    uVar17 = (*(int *)(local_3ae + -uVar17) << uVar17 * 8 |
                             uVar11 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar1 + 1) * 8 |
                             *(uint *)(local_3ae + 3 + -uVar1) >> (3 - uVar1) * 8;
                    cVar15 = (char)uVar17;
                    local_654 = CONCAT13(cVar15,local_654._1_3_);
                    if (uVar17 == 4) {
                      if (iVar6 == 0) {
                        local_654 = CONCAT13(1,local_654._1_3_);
                        goto LAB_005df5ec;
                      }
                    }
                    else {
LAB_005df5ec:
                      cVar15 = local_654._0_1_;
                    }
                    if (cVar15 != '\0') {
                      cVar14 = (char)local_3a6;
                      if (cVar15 != '\x01') {
                        uVar17 = (uint)local_3aa & 3;
                        local_3aa[3] = (byte)(*(int *)(local_3aa + -uVar17) << uVar17 * 8) |
                                       (byte)(0xffffffff >> (4 - uVar17) * 8) & 4;
                        if (cVar15 != '\x04') {
                          uVar17 = (uint)local_3aa & 3;
                          if (cVar15 == '\x02') {
                            uVar21 = (uint)(local_3aa + 3) & 3;
                            local_5bc = ((byte)(*(int *)(local_3aa + -uVar17) << uVar17 * 8) |
                                        (byte)(0xffffffff >> (4 - uVar17) * 8) & 2) &
                                        (byte)(-1 << (uVar21 + 1) * 8) |
                                        (byte)(*(uint *)(local_3aa + 3 + -uVar21) >>
                                              (3 - uVar21) * 8);
                            local_5ba = local_3a2;
                            local_5bb = cVar14;
                            if ((local_3a6 & 0xff) == 1) {
                              uVar21 = rdmngr_db_rd_entry_get(pcVar5,auStack_56c);
                              uVar17 = (uint)&local_3a2 & 3;
                              local_5ba = *(int *)((int)&local_3a2 - uVar17) << uVar17 * 8 |
                                          uVar21 & 0xffffffffU >> (4 - uVar17) * 8;
                              if ((uVar21 == 0) &&
                                 (local_5ba = local_3a2, (byte)(local_563 - 3U) < 2)) {
                                local_5bb = '\x02';
                              }
                            }
                            pcVar5 = acStack_39e;
                            iVar6 = cw_ipstr_to_protocol_ip(pcVar5,auStack_5b6);
                            if (iVar6 == 0) {
                              memcpy(auStack_5a2,auStack_5b6,0x14);
                              memcpy(auStack_58e,auStack_5b6,0x14);
                              local_57a = local_376._2_2_;
                              local_578 = local_372._2_2_;
                              local_576 = local_578;
                              sVar8 = strlen(acStack_36e);
                              uVar17 = sVar8 & 0xffff;
                              local_574 = (ushort)sVar8;
                              local_572 = (void *)FUN_00408450(uVar17,0x575);
                              if (local_572 != (void *)0x0) {
                                memcpy(local_572,acStack_36e,(uint)local_574);
                                local_654._1_3_ = (undefined3)((uint)&local_5bc >> 8);
                                local_650._0_1_ = SUB41(&local_5bc,0);
                                goto LAB_005df7a8;
                              }
                              uVar21 = (uint)(auStack_608 + 3) & 3;
                              uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                       uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                              if (g_wserv_error != 0) {
                                iVar6 = is_target_debug_ap();
                                if (iVar6 != 0) {
                                  pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                                  uVar20 = 0x578;
                                  goto LAB_005dec70;
                                }
                                uVar21 = (uint)(auStack_608 + 3) & 3;
                                uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                         uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                              }
                            }
                            else {
                              uVar17 = (uint)(auStack_608 + 3) & 3;
                              uVar17 = *(int *)(auStack_608 + 3 + -uVar17) << uVar17 * 8 |
                                       (uint)pcVar5 & 0xffffffffU >> (4 - uVar17) * 8;
                              if (g_wserv_error != 0) {
                                iVar6 = is_target_debug_ap();
                                if (iVar6 != 0) {
                                  uVar20 = 0x56a;
                                  goto LAB_005def1c;
                                }
                                uVar21 = (uint)(auStack_608 + 3) & 3;
                                uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                         uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                              }
                            }
                          }
                          else {
                            uVar17 = (uint)(auStack_608 + 3) & 3;
                            uVar17 = *(int *)(auStack_608 + 3 + -uVar17) << uVar17 * 8 |
                                     (uint)pcVar9 & 0xffffffffU >> (4 - uVar17) * 8;
                            if (g_wserv_error != 0) {
                              iVar6 = is_target_debug_ap();
                              if (iVar6 != 0) {
                                uVar17 = (uint)local_3ae & 3;
                                uVar17 = *(int *)(local_3ae + -uVar17) << uVar17 * 8 |
                                         uVar21 & 0xffffffffU >> (4 - uVar17) * 8;
                                uVar20 = 0x583;
                                goto LAB_005dee70;
                              }
                              uVar21 = (uint)(auStack_608 + 3) & 3;
                              uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                       uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                            }
                          }
                          goto LAB_005deaac;
                        }
                      }
                      uVar17 = local_3a2;
                      local_688 = local_3aa[3];
                      cStack_687 = cVar14;
                      if ((local_3a6 & 0xff) == 1) {
                        uVar21 = rdmngr_db_rd_entry_get(pcVar5,auStack_56c);
                        uVar17 = (uint)&local_3a2 & 3;
                        uVar17 = *(int *)((int)&local_3a2 - uVar17) << uVar17 * 8 |
                                 uVar21 & 0xffffffffU >> (4 - uVar17) * 8;
                        if (uVar21 == 0) {
                          uVar21 = (uint)((byte)(local_563 - 3U) < 2);
                          uVar17 = (uint)&local_3a2 & 3;
                          uVar17 = *(int *)((int)&local_3a2 - uVar17) << uVar17 * 8 |
                                   uVar21 & 0xffffffffU >> (4 - uVar17) * 8;
                          if (uVar21 != 0) {
                            cStack_687 = '\x02';
                            uVar17 = local_3a2;
                          }
                        }
                      }
                      uStack_686 = (undefined2)(uVar17 >> 0x10);
                      local_684 = (undefined2)uVar17;
                      sVar8 = strlen(acStack_39e);
                      uVar17 = sVar8 & 0xffff;
                      uStack_682 = (ushort)sVar8;
                      local_680 = (char *)FUN_00408450(uVar17,0x553);
                      if (local_680 == (char *)0x0) {
                        uVar21 = (uint)(auStack_608 + 3) & 3;
                        uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                 uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                        if (g_wserv_error != 0) {
                          iVar6 = is_target_debug_ap();
                          if (iVar6 != 0) {
                            pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                            uVar20 = 0x556;
                            goto LAB_005dec70;
                          }
                          uVar21 = (uint)(auStack_608 + 3) & 3;
                          uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                   uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                        }
                        goto LAB_005deaac;
                      }
                      memcpy(local_680,acStack_39e,(uint)uStack_682);
                      local_654._1_3_ = (undefined3)((uint)&local_688 >> 8);
                      local_650._0_1_ = SUB41(&local_688,0);
                    }
LAB_005df7a8:
                    local_640 = 0;
                    local_63c = 0;
                    local_638 = 0;
                    local_648 = 0x12345678;
                    local_644 = 0x630000;
                    FUN_0051ad88(&local_640);
                    uVar17 = uVar22;
                    iVar6 = cw_service_msg_add(uVar22,0x25,&local_648,1,99,&local_65c);
                    if (iVar6 != 0) {
                      uVar21 = (uint)(auStack_608 + 3) & 3;
                      uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                               uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                      if (g_wserv_error != 0) {
                        iVar6 = is_target_debug_ap();
                        if (iVar6 != 0) {
                          pcVar5 = "<wserv>[error]%s(): %d  -> cw_service_msg_add() fail!\r\n";
                          uVar20 = 0x593;
                          goto LAB_005dec70;
                        }
                        uVar21 = (uint)(auStack_608 + 3) & 3;
                        uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                 uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                      }
                      goto LAB_005deaac;
                    }
                  }
                }
                else {
                  pcVar9 = (char *)strlen(acStack_518);
                  uVar17 = 1;
                  if (0x7f < (int)pcVar9) {
                    pcVar9 = (char *)0x80;
                  }
                  local_62c = SUB42(pcVar9,0);
                  pvVar10 = (void *)FUN_004082a0(1,pcVar9,0x45a);
                  uStack_62a = (undefined2)((uint)pvVar10 >> 0x10);
                  local_628 = SUB42(pvVar10,0);
                  if (pvVar10 == (void *)0x0) {
                    uVar11 = (uint)local_3b6 & 3;
                    local_3b6[3] = (byte)(*(int *)(local_3b6 + -uVar11) << uVar11 * 8);
                    if (pcVar9 != (char *)0x0) {
                      uVar21 = (uint)(auStack_608 + 3) & 3;
                      uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                               uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                      if (g_wserv_error != 0) {
                        iVar6 = is_target_debug_ap();
                        if (iVar6 != 0) {
                          pcVar5 = "<wserv>[error]%s(): %d  -> no memory! ssid_id_len:%d\r\n";
                          uVar20 = 0x45e;
                          goto LAB_005dedf0;
                        }
                        uVar21 = (uint)(auStack_608 + 3) & 3;
                        uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                 uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                      }
                      goto LAB_005deaac;
                    }
                  }
                  else if (pcVar9 == (char *)0x0) {
                    uVar17 = (uint)local_3b6 & 3;
                    local_3b6[3] = (byte)(*(int *)(local_3b6 + -uVar17) << uVar17 * 8) |
                                   (byte)pvVar10 & (byte)(0xffffffff >> (4 - uVar17) * 8);
                  }
                  else {
                    memcpy(pvVar10,acStack_518,(size_t)pcVar9);
                  }
                  local_630 = CONCAT22(100,CONCAT11(3,local_3b6[3]));
                  uStack_626 = uStack_3fa;
                  if ((g_wserv_debug != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
                    uVar21 = local_630 >> 8 & 0xff;
                    printf("<wserv>[debug]%s(): %d  -> priv_wsrv_val_enable.network_type=%d, wserv_entry->id=%d\r\n"
                           ,"_uac_wserv_add_packet_create",0x46c,uVar21,local_498);
                  }
                  local_634 = CONCAT13(bVar2,local_634._1_3_) & 0xfffffff;
                  local_634._1_3_ = CONCAT12(cVar24,local_634._2_2_);
                  uVar11 = wserv_db_rd_get_bind_vlan_by_wserv_id
                                     (pcVar5,local_498,(int)&local_634 + 2);
                  uVar17 = (uint)local_3ae & 3;
                  if (uVar11 != 0) {
                    uVar17 = (uint)(auStack_608 + 3) & 3;
                    uVar17 = *(int *)(auStack_608 + 3 + -uVar17) << uVar17 * 8 |
                             (uint)pcVar5 & 0xffffffffU >> (4 - uVar17) * 8;
                    if (g_wserv_error != 0) {
                      iVar6 = is_target_debug_ap();
                      if (iVar6 != 0) {
                        pcVar5 = 
                        "<wserv>[error]%s(): %d  -> wserv_db_rd_get_bind_vlan_by_wserv_id() fail!\r\n"
                        ;
                        uVar20 = 0x472;
                        goto LAB_005dec70;
                      }
                      uVar21 = (uint)(auStack_608 + 3) & 3;
                      uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                               uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                    }
                    goto LAB_005deaac;
                  }
                  uVar1 = (uint)(local_3ae + 3) & 3;
                  uVar17 = (*(int *)(local_3ae + -uVar17) << uVar17 * 8 |
                           uVar11 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar1 + 1) * 8 |
                           *(uint *)(local_3ae + 3 + -uVar1) >> (3 - uVar1) * 8;
                  bStack_625 = (byte)uVar17;
                  if ((uVar17 == 4) && (iVar6 == 0)) {
                    bStack_625 = 1;
                  }
                  if (bStack_625 != 0) {
                    if (bStack_625 != 1) {
                      if (bStack_625 != 4) {
                        uVar17 = (uint)local_3aa & 3;
                        if (bStack_625 == 2) {
                          pcVar5 = acStack_39e;
                          uVar21 = (uint)(local_3aa + 3) & 3;
                          local_5bc = ((byte)(*(int *)(local_3aa + -uVar17) << uVar17 * 8) |
                                      bStack_625 & (byte)(0xffffffff >> (4 - uVar17) * 8)) &
                                      (byte)(-1 << (uVar21 + 1) * 8) |
                                      (byte)(*(uint *)(local_3aa + 3 + -uVar21) >> (3 - uVar21) * 8)
                          ;
                          local_5ba = local_3a2;
                          local_5bb = (char)local_3a6;
                          iVar6 = cw_ipstr_to_protocol_ip(pcVar5,auStack_5b6);
                          if (iVar6 == 0) {
                            memcpy(auStack_5a2,auStack_5b6,0x14);
                            memcpy(auStack_58e,auStack_5b6,0x14);
                            local_57a = local_376._2_2_;
                            local_578 = local_372._2_2_;
                            local_576 = local_578;
                            sVar8 = strlen(acStack_36e);
                            uVar17 = sVar8 & 0xffff;
                            local_574 = (ushort)sVar8;
                            local_572 = (void *)FUN_00408450(uVar17,0x4a1);
                            if (local_572 != (void *)0x0) {
                              memcpy(local_572,acStack_36e,(uint)local_574);
                              local_624 = &local_5bc;
                              goto LAB_005def84;
                            }
                            uVar21 = (uint)(auStack_608 + 3) & 3;
                            uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                     uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                            if (g_wserv_error != 0) {
                              iVar6 = is_target_debug_ap();
                              if (iVar6 != 0) {
                                pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                                uVar20 = 0x4a4;
                                goto LAB_005dec70;
                              }
                              uVar21 = (uint)(auStack_608 + 3) & 3;
                              uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                       uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                            }
                            goto LAB_005deaac;
                          }
                          uVar17 = (uint)(auStack_608 + 3) & 3;
                          uVar17 = *(int *)(auStack_608 + 3 + -uVar17) << uVar17 * 8 |
                                   (uint)pcVar5 & 0xffffffffU >> (4 - uVar17) * 8;
                          if (g_wserv_error == 0) goto LAB_005deaac;
                          iVar6 = is_target_debug_ap();
                          if (iVar6 == 0) {
                            uVar21 = (uint)(auStack_608 + 3) & 3;
                            uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                     uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                            goto LAB_005deaac;
                          }
                          uVar20 = 0x496;
LAB_005def1c:
                          pcVar5 = 
                          "<wserv>[error]%s(): %d  -> invalid wpa radius server ip: %s!\r\n";
                          pcVar9 = acStack_39e;
                        }
                        else {
                          uVar17 = (uint)(auStack_608 + 3) & 3;
                          uVar17 = *(int *)(auStack_608 + 3 + -uVar17) << uVar17 * 8 |
                                   (uint)pcVar5 & 0xffffffffU >> (4 - uVar17) * 8;
                          if (g_wserv_error == 0) goto LAB_005deaac;
                          iVar6 = is_target_debug_ap();
                          if (iVar6 == 0) {
                            uVar21 = (uint)(auStack_608 + 3) & 3;
                            uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                     uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                            goto LAB_005deaac;
                          }
                          uVar17 = (uint)local_3ae & 3;
                          uVar17 = *(int *)(local_3ae + -uVar17) << uVar17 * 8 |
                                   uVar21 & 0xffffffffU >> (4 - uVar17) * 8;
                          uVar20 = 0x4af;
LAB_005dee70:
                          pcVar5 = "<wserv>[error]%s(): %d  -> invalid sec_type: %d!\r\n";
                          uVar21 = (uint)(local_3ae + 3) & 3;
                          pcVar9 = (char *)(uVar17 & -1 << (uVar21 + 1) * 8 |
                                           *(uint *)(local_3ae + 3 + -uVar21) >> (3 - uVar21) * 8);
                        }
                        goto LAB_005dedf0;
                      }
                      uVar17 = (uint)local_3aa & 3;
                      local_3aa[3] = (byte)(*(int *)(local_3aa + -uVar17) << uVar17 * 8) |
                                     (byte)(0xffffffff >> (4 - uVar17) * 8) & 4;
                    }
                    uStack_686 = (undefined2)(local_3a2 >> 0x10);
                    local_684 = (undefined2)local_3a2;
                    local_688 = local_3aa[3];
                    cStack_687 = (char)local_3a6;
                    sVar8 = strlen(acStack_39e);
                    uVar17 = sVar8 & 0xffff;
                    uStack_682 = (ushort)sVar8;
                    local_680 = (char *)FUN_00408450(uVar17,0x484);
                    if (local_680 == (char *)0x0) {
                      uVar21 = (uint)(auStack_608 + 3) & 3;
                      uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                               uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                      if (g_wserv_error != 0) {
                        iVar6 = is_target_debug_ap();
                        if (iVar6 != 0) {
                          pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                          uVar20 = 0x487;
                          goto LAB_005dec70;
                        }
                        uVar21 = (uint)(auStack_608 + 3) & 3;
                        uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                                 uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                      }
                      goto LAB_005deaac;
                    }
                    memcpy(local_680,acStack_39e,(uint)uStack_682);
                    local_624 = &local_688;
                  }
LAB_005def84:
                  local_640 = 0;
                  local_63c = 0;
                  local_638 = 0;
                  local_648 = 0x12345678;
                  local_644 = 0x940000;
                  FUN_0051ad88(&local_640);
                  uVar17 = uVar22;
                  iVar6 = cw_service_msg_add(uVar22,0x25,&local_648,1,0x94,&local_634);
                  if (iVar6 != 0) {
                    uVar21 = (uint)(auStack_608 + 3) & 3;
                    uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                             uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                    if (g_wserv_error != 0) {
                      iVar6 = is_target_debug_ap();
                      if (iVar6 != 0) {
                        pcVar5 = "<wserv>[error]%s(): %d  -> cw_service_msg_add() fail!\r\n";
                        uVar20 = 0x4bf;
                        goto LAB_005dec70;
                      }
                      uVar21 = (uint)(auStack_608 + 3) & 3;
                      uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                               uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                    }
                    goto LAB_005deaac;
                  }
                }
                uVar17 = local_38 + 0x10;
                iVar6 = capwap_packet_assemble(uVar17,uVar22);
                if (iVar6 != -1) {
                  iVar23 = 0;
                  goto LAB_005deaa8;
                }
                uVar21 = (uint)(auStack_608 + 3) & 3;
                uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                         uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                if (g_wserv_error != 0) {
                  iVar6 = is_target_debug_ap();
                  if (iVar6 != 0) {
                    pcVar5 = "<wserv>[error]%s(): %d  -> capwap_packet_assemble() fail!\r\n";
                    uVar20 = 0x59b;
                    goto LAB_005dec70;
                  }
                  uVar21 = (uint)(auStack_608 + 3) & 3;
                  uVar17 = *(int *)(auStack_608 + 3 + -uVar21) << uVar21 * 8 |
                           uVar17 & 0xffffffffU >> (4 - uVar21) * 8;
                }
              }
            }
            else {
              iVar23 = -1;
              if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
              goto LAB_005deaa8;
              pcVar5 = "<wserv>[error]%s(): %d  -> invalid encode type(%d).\r\n";
              uVar20 = 0x425;
              pcVar9 = local_3ec;
LAB_005dedf0:
              printf(pcVar5,"_uac_wserv_add_packet_create",uVar20,pcVar9);
LAB_005dec78:
              uVar17 = CONCAT13(auStack_608[3],uStack_604);
            }
          }
LAB_005deaac:
          if (uVar17 == 0) {
            uVar17 = (uint)&local_572 & 3;
            pvVar10 = (void *)(*(int *)((int)&local_572 - uVar17) << uVar17 * 8);
          }
          else {
            FUN_00407df0();
            auStack_608 = (undefined1  [4])((uint)auStack_608 & 0xffffff00);
            uStack_604 = 0;
            pvVar10 = local_572;
          }
          if (pvVar10 != (void *)0x0) {
            FUN_00407df0();
            local_572 = (void *)0x0;
          }
          if (local_680 != (char *)0x0) {
            FUN_00407df0();
            local_680 = (char *)0x0;
          }
          if (local_5e4 == (void *)0x0) {
            iVar6 = CONCAT22(uStack_62a,local_628);
          }
          else {
            FUN_00407df0();
            local_5e4 = (void *)0x0;
            iVar6 = CONCAT22(uStack_62a,local_628);
          }
          if (iVar6 != 0) {
            FUN_00407df0();
            uStack_62a = 0;
            local_628 = 0;
          }
          if (uVar22 != 0) {
            cw_parsed_pkt_destroy(uVar22);
          }
          if (iVar23 == 0) {
            FUN_004086b0(param_2,iVar4);
            iVar4 = apmngr_db_capacity_support(local_300,1,0xd);
            if (iVar4 == 0) {
LAB_005dfc74:
              _uac_wserv_packet_type_set_by_wlan_id
                        (local_300,(int)local_67c._0_1_,local_67c._1_1_,0x10);
              _uac_wserv_packet_next_cur_id_update_by_ap_id(local_300);
              iVar4 = apmngr_db_is_ap_support_ssid_mlo_feature(local_300);
              if ((iVar4 != 1) || (local_3ae == (undefined1  [4])0x0)) goto LAB_005de560;
              iVar4 = cw_user_send_pkt_node_create(1,0);
              if (iVar4 == 0) {
LAB_005de5f8:
                FUN_00407f30(DAT_007598e4);
                if (iVar4 == 0) {
                  return 0;
                }
                cw_user_send_pkt_node_destroy(iVar4);
                return 0;
              }
              local_68c = bVar2 & 0xf;
              iVar23 = *(int *)(iVar4 + 0xc);
              local_68a = cStack_3ed;
              local_670 = 0;
              local_66c = 0;
              local_668 = 0;
              local_664 = (byte *)0x0;
              local_660 = 0;
              local_688 = 0;
              cStack_687 = '\0';
              uStack_686 = 0;
              local_684 = 0;
              uStack_682 = 0;
              local_680 = (char *)0x0;
              cStack_68b = cVar24;
              iVar6 = cw_parsed_pkt_create(7);
              if (iVar6 != 0) {
                FUN_0051ad88(&local_668);
                cStack_687 = '\0';
                uStack_686 = 0;
                local_680 = (char *)0x0;
                local_688 = local_68c;
                local_684 = 0;
                uStack_682 = 8;
                local_680 = (char *)FUN_00408450(8,0x3c3);
                if (local_680 == (char *)0x0) {
                  if ((g_wserv_error != 0) && (iVar23 = is_target_debug_ap(), iVar23 != 0)) {
                    printf("<wserv>[error]%s(): %d  -> no memory!\r\n",
                           "_uac_wserv_ssid_mlo_switch_pkt_create",0x3c6);
                  }
                }
                else {
                  *local_680 = cStack_68b;
                  local_680[1] = '\0';
                  local_680[2] = '\0';
                  local_680[3] = '\0';
                  local_680[4] = '\x03';
                  local_680[5] = '\x02';
                  local_680[6] = '\x01';
                  local_680[7] = local_68a;
                  iVar7 = cw_service_msg_add(iVar6,0x25,&local_670,1,0xc0,&local_688);
                  if (iVar7 == 0) {
                    if (wserv_pkt_switch != '\0') {
                      capwap_parsed_packet_dump(iVar6);
                    }
                    iVar23 = capwap_packet_assemble(iVar23 + 0x10,iVar6);
                    if (iVar23 != -1) {
                      cw_parsed_pkt_destroy(iVar6);
                      if ((g_wserv_debug != 0) && (iVar6 = is_target_debug_ap(param_2), iVar6 != 0))
                      {
                        printf("<wserv>[debug]%s(): %d  -> Create mlo switch pkt successfully\r\n",
                               "_uac_wserv_packet_send_callback",0x646);
                      }
                      FUN_004086b0(param_2,iVar4);
                      goto LAB_005de560;
                    }
                  }
                }
                if (local_680 != (char *)0x0) {
                  FUN_00407df0();
                  local_680 = (char *)0x0;
                }
                cw_parsed_pkt_destroy(iVar6);
              }
              if (g_wserv_warning == 0) {
                iVar6 = *(int *)(iVar4 + 0xc);
              }
              else {
                iVar6 = is_target_debug_ap();
                if (iVar6 != 0) {
                  pcVar5 = 
                  "<wserv>[warning]%s(): %d  -> _uac_wserv_ssid_mlo_switch_pkt_create() fail.\r\n";
                  uVar20 = 0x641;
                  goto LAB_005dfabc;
                }
                iVar6 = *(int *)(iVar4 + 0xc);
              }
            }
            else {
              iVar4 = cw_user_send_pkt_node_create(1,0);
              if (iVar4 == 0) goto LAB_005de5f8;
              iVar23 = *(int *)(iVar4 + 0xc);
              local_670 = 0;
              local_66c = 0;
              local_668 = 0;
              local_664 = (byte *)0x0;
              local_688 = 0;
              cStack_687 = '\0';
              local_65c = 0;
              local_658 = 0;
              local_654 = 0;
              local_650 = 0;
              local_64c = 0;
              iVar6 = cw_parsed_pkt_create(7);
              if (iVar6 == 0) {
                if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                  printf("<wserv>[error]%s(): %d  -> no memory!\r\n",
                         "_uac_wserv_bw_ctrl_packet_create",0x36e);
                }
              }
              else {
                local_688 = bVar2 & 0xf;
                local_664 = &local_688;
                if (local_322 == '\0') {
                  local_670 = CONCAT13(1,local_670._1_3_);
LAB_005dfb68:
                  local_65c = 0x12345678;
                  local_658 = CONCAT22(0x45,local_658._2_2_);
                  cStack_687 = cVar24;
                  FUN_0051ad88(&local_654);
                  iVar7 = cw_service_msg_add(iVar6,0x25,&local_65c,1,0x45,&local_670);
                  if (iVar7 == 0) {
                    iVar7 = capwap_packet_assemble(iVar23 + 0x10,iVar6);
                    iVar23 = 0;
                    if (((iVar7 == -1) && (iVar23 = -1, g_wserv_error != 0)) &&
                       (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
                      pcVar5 = "<wserv>[error]%s(): %d  -> capwap_packet_assemble() fail!\r\n";
                      uVar20 = 0x3a1;
                      goto LAB_005dfc58;
                    }
                  }
                  else {
                    iVar23 = -1;
                    if ((g_wserv_error != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
                      pcVar5 = "<wserv>[error]%s(): %d  -> cw_service_msg_add() fail!\r\n";
                      uVar20 = 0x39a;
LAB_005dfc58:
                      printf(pcVar5,"_uac_wserv_bw_ctrl_packet_create",uVar20);
                      goto LAB_005dfc60;
                    }
                  }
                }
                else {
                  if (local_321 == '\0') {
                    uVar16 = 3;
LAB_005dfec8:
                    local_670 = CONCAT13(uVar16,local_670._1_3_);
                    local_66c = local_32a;
                    local_668 = local_326;
                    goto LAB_005dfb68;
                  }
                  uVar16 = 2;
                  if (local_321 == '\x01') goto LAB_005dfec8;
                  iVar23 = -1;
                  cStack_687 = cVar24;
                  if ((g_wserv_error == 0) || (iVar7 = is_target_debug_ap(), iVar7 == 0))
                  goto LAB_005dfbcc;
                  printf("<wserv>[error]%s(): %d  -> invalid bw_ctrl_type [%d]!\r\n",
                         "_uac_wserv_bw_ctrl_packet_create",0x387,local_670 >> 0x18);
LAB_005dfc60:
                  iVar23 = -1;
                }
LAB_005dfbcc:
                cw_parsed_pkt_destroy(iVar6);
                if (iVar23 == 0) {
                  FUN_004086b0(param_2,iVar4);
                  goto LAB_005dfc74;
                }
              }
              if (g_wserv_warning == 0) {
                iVar6 = *(int *)(iVar4 + 0xc);
              }
              else {
                iVar6 = is_target_debug_ap();
                if (iVar6 != 0) {
                  pcVar5 = 
                  "<wserv>[warning]%s(): %d  -> _uac_wserv_bw_ctrl_packet_create() fail.\r\n";
                  uVar20 = 0x627;
                  goto LAB_005dfabc;
                }
                iVar6 = *(int *)(iVar4 + 0xc);
              }
            }
          }
          else if (g_wserv_warning == 0) {
            iVar6 = *(int *)(iVar4 + 0xc);
          }
          else {
            iVar6 = is_target_debug_ap();
            if (iVar6 == 0) {
              iVar6 = *(int *)(iVar4 + 0xc);
            }
            else {
              pcVar5 = "<wserv>[warning]%s(): %d  -> _uac_wserv_add_packet_create() fail.\r\n";
              uVar20 = 0x617;
LAB_005dfabc:
              printf(pcVar5,"_uac_wserv_packet_send_callback",uVar20);
              iVar6 = *(int *)(iVar4 + 0xc);
            }
          }
          *(undefined4 *)(iVar6 + 8) = 1;
          cw_user_send_pkt_node_destroy(iVar4);
          iVar4 = (int)local_67c._0_1_;
          goto LAB_005de6b8;
        }
        iVar4 = (int)local_67c._0_1_;
        if (g_wserv_warning == 0) goto LAB_005de6b8;
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = (int)local_67c._0_1_;
          goto LAB_005de6b8;
        }
        pcVar5 = "<wserv>[warning]%s(): %d  -> wserv_db_get_entry_by_id() fail.\r\n";
        uVar20 = 0x601;
      }
      printf(pcVar5,"_uac_wserv_packet_send_callback",uVar20);
      iVar4 = (int)local_67c._0_1_;
LAB_005de6b8:
      _uac_wserv_packet_type_set_by_wlan_id(local_300,iVar4,local_67c._1_1_,0);
      _uac_wserv_packet_next_cur_id_update_by_ap_id(local_300);
      FUN_00407f30(DAT_007598e4);
      return 2;
    }
    _uac_wserv_igmp_snooping_switch_to_ap(local_300);
    _uac_wserv_igmp_query_switch_to_ap(local_300);
    if ((g_wserv_debug != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> apid = %d, entry.is_rrm = %d\r\n",
             "_uac_wserv_packet_send_callback",0x664,(uint)local_300,(uint)local_60);
    }
    uVar3 = local_300;
    if (local_60 != 1) {
      uVar20 = apmngr_db_timer_md5_send_interval_default_get(local_300);
      iVar4 = apmngr_entry_timer_start(uVar3,1,uVar20);
      if (iVar4 != 0) {
        iVar4 = 0;
        if ((g_wserv_warning != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> ap(%d) is running rrm or apmngr_entry_timer_start() fail.\r\n"
                 ,"_uac_wserv_packet_send_callback",0x667,(uint)local_300);
        }
        goto LAB_005de5f8;
      }
    }
    _uac_wserv_packet_md5_type_set_by_ap_id(local_300,0);
  }
  _uac_wserv_packet_waiting_status_set_by_ap_id(local_300,0);
LAB_005de560:
  FUN_00407f30(DAT_007598e4);
  return 1;
}

