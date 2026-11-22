// func _roaming_nbr_packet_create @ 00487610 size=3692

/* WARNING: Removing unreachable block (ram,0x00487c84) */
/* WARNING: Removing unreachable block (ram,0x00487f08) */

undefined4
_roaming_nbr_packet_create
          (undefined2 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5
          ,int *param_6)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  char *pcVar12;
  undefined4 uVar13;
  int iVar14;
  void *__dest;
  int *piVar15;
  undefined8 uVar16;
  int local_258;
  int local_254;
  int local_250;
  undefined4 local_24c;
  uint local_248;
  undefined4 local_244;
  int local_240;
  int local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined1 auStack_224 [36];
  undefined1 auStack_200 [24];
  undefined4 local_1e8;
  uint local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  int local_1d8 [12];
  int local_1a8 [12];
  undefined2 uStack_178;
  byte abStack_176 [2];
  uint auStack_174 [2];
  undefined1 local_16c;
  undefined8 local_168;
  undefined2 uStack_160;
  byte abStack_15e [2];
  uint auStack_15c [7];
  byte local_140;
  char acStack_138 [256];
  uint local_38;
  int local_34;
  int local_30;
  int *local_2c;
  
  memset(acStack_138,0,0x100);
  local_238 = 0;
  local_234 = 0;
  local_230 = 0;
  local_22c = 0;
  local_228 = 0;
  local_24c = 0;
  local_248 = 0;
  local_244 = 0;
  local_240 = 0;
  local_23c = 0;
  local_258 = 0;
  memset(auStack_224,0,0x22);
  memset(auStack_200,0,0x28);
  local_34 = FUN_004080a0(_ap_union_obj,_ap_union_key,_ap_union_cmp,0x10);
  if (local_34 == 0) {
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[WSTA_ROAM_ERROR]%s()/%d create ap union hash failed\n","_roaming_nbr_packet_create",
           0x343);
    return 0xffffffff;
  }
  wsta_roam_db_cfg_get(auStack_224);
  local_30 = cw_parsed_pkt_create(7);
  if (local_30 == 0) {
    if (wsta_roam_err_switch == '\0') {
      iVar14 = -1;
    }
    else {
      iVar14 = -1;
      printf("[WSTA_ROAM_ERROR]%s()/%d cw_parsed_pkt_create failed\n","_roaming_nbr_packet_create",
             0x34c);
    }
    goto LAB_004878b0;
  }
  FUN_0051ad88(&local_230);
  local_240 = FUN_004082a0(0x80,6,0x352);
  if (local_240 == 0) {
    iVar14 = -1;
    if (wsta_roam_err_switch != '\0') {
      pcVar12 = "[WSTA_ROAM_ERROR]%s()/%d Out of memory\n";
      uVar13 = 0x355;
LAB_004882b8:
      iVar14 = -1;
      printf(pcVar12,"_roaming_nbr_packet_create",uVar13);
    }
  }
  else {
    local_23c = FUN_004082a0(0x80,0x1c,0x358);
    if (local_23c == 0) {
      iVar14 = -1;
      if (wsta_roam_err_switch != '\0') {
        pcVar12 = "[WSTA_ROAM_ERROR]%s()/%d Out of memory\n";
        uVar13 = 0x35b;
        goto LAB_004882b8;
      }
    }
    else {
      if (wsta_roam_strategy_switch != '\0') {
        printf("[WSTA_ROAM_STRATEGY]%s()/%d add current ap mac[%02x:%02x:%02x:%02x:%02x:%02x] to ap union.\n"
               ,"_roaming_nbr_packet_create",0x35f,(uint)*(byte *)(param_1 + 1),
               (uint)*(byte *)((int)param_1 + 3),(uint)*(byte *)(param_1 + 2),
               (uint)*(byte *)((int)param_1 + 5),(uint)*(byte *)(param_1 + 3),
               (uint)*(byte *)((int)param_1 + 7));
      }
      iVar14 = -1;
      iVar2 = _ap_union_hash_add(param_1 + 1,local_34,local_240,&local_244,&local_258);
      if (iVar2 != -1) {
        local_24c = CONCAT13((char)iVar2,CONCAT12(*(undefined1 *)(param_1 + 4),local_24c._2_2_));
        apmngr_db_get_addr_by_capacity(*param_1,param_3,1,1,0x15f0000,1,0x19);
        local_38 = 0;
        while ((param_5 != 0 && ((int)local_38 < 0x80))) {
          memset(&uStack_178,0,0x40);
          if (wsta_roam_strategy_switch != '\0') {
            printf("[WSTA_ROAM_STRATEGY]%s()/%d ====One station set begin====\n",
                   "_roaming_nbr_packet_create",0x36e);
          }
          if (wsta_roam_strategy_switch != '\0') {
            uVar3 = (uint)*(byte *)(param_5 + 0xd);
            uVar4 = (uint)*(byte *)(param_5 + 0xe);
            uVar5 = (uint)*(byte *)(param_5 + 0xf);
            uVar6 = (uint)*(byte *)(param_5 + 0x10);
            uVar7 = (uint)*(byte *)(param_5 + 0x11);
            uVar8 = (uint)*(char *)(param_5 + 0x17);
            uVar9 = (uint)*(byte *)(param_5 + 0x15);
            printf("[WSTA_ROAM_STRATEGY]%s()/%d nbr select for station[%02x:%02x:%02x:%02x:%02x:%02x], rssi=%d, band_type=%d.\n"
                   ,"_roaming_nbr_packet_create",0x377,(uint)*(byte *)(param_5 + 0xc),uVar3,uVar4,
                   uVar5,uVar6,uVar7,uVar8,uVar9);
            if (wsta_roam_strategy_switch != '\0') {
              printf("[WSTA_ROAM_STRATEGY]%s()/%d   nbr_count_2g=%d, list: \n",
                     "_roaming_nbr_packet_create",0x379,(uint)*(byte *)(param_5 + 0x1c),uVar3,uVar4,
                     uVar5,uVar6,uVar7,uVar8,uVar9);
            }
            iVar14 = 0;
            do {
              bVar1 = *(byte *)(param_5 + 0x1c);
              while( true ) {
                if ((int)(uint)bVar1 <= iVar14) {
                  if (wsta_roam_strategy_switch != '\0') {
                    printf("[WSTA_ROAM_STRATEGY]%s()/%d   nbr_count_5g=%d, list: \n",
                           "_roaming_nbr_packet_create",899,(uint)*(byte *)(param_5 + 0x1d),uVar3,
                           uVar4,uVar5,uVar6,uVar7,uVar8,uVar9);
                  }
                  iVar14 = 0;
                  goto LAB_00488014;
                }
                if (wsta_roam_strategy_switch == '\0') break;
                pbVar10 = (byte *)(param_5 + iVar14 * 0x18 + 0x20);
                uVar3 = (uint)pbVar10[9];
                uVar4 = (uint)(char)pbVar10[0xc];
                uVar5 = *(uint *)(pbVar10 + 0x14);
                uVar6 = (uint)*pbVar10;
                uVar7 = (uint)pbVar10[1];
                uVar8 = (uint)pbVar10[2];
                uVar9 = (uint)pbVar10[3];
                printf("[WSTA_ROAM_STRATEGY]%s()/%d     [idx=%d]channel-load=%u, rssi=%d, estimated_rate=%d, ap-mac=[%02x:%02x:%02x:%02x:%02x:%02x], radio_id=%u, channel=%u, wlan_id=%u, bssid=[%02x:%02x:%02x:%02x:%02x:%02x]\n"
                       ,"_roaming_nbr_packet_create",0x380,iVar14,uVar3,uVar4,uVar5,uVar6,uVar7,
                       uVar8,uVar9,(uint)pbVar10[4],(uint)pbVar10[5],(uint)pbVar10[8],
                       (uint)pbVar10[10],(uint)pbVar10[0xd],(uint)pbVar10[0xe],(uint)pbVar10[0xf],
                       (uint)pbVar10[0x10],(uint)pbVar10[0x11],(uint)pbVar10[0x12],
                       (uint)pbVar10[0x13]);
                bVar1 = *(byte *)(param_5 + 0x1c);
                iVar14 = iVar14 + 1;
              }
              iVar14 = iVar14 + 1;
            } while( true );
          }
LAB_00487a8c:
          local_250 = 0;
          piVar15 = local_1d8;
          local_254 = 0;
          _roaming_nbr_select(auStack_224,param_5,&local_250,local_1a8,&local_254,piVar15,6);
          if (wsta_roam_strategy_switch != '\0') {
            printf("[WSTA_ROAM_STRATEGY]%s()/%d nbr select result: \n","_roaming_nbr_packet_create",
                   0x396);
            iVar14 = 0;
            memset(acStack_138,0,0x100);
            while (iVar14 < local_254) {
              if (iVar14 == 0) {
                iVar14 = 1;
                piVar15 = piVar15 + 1;
                sprintf(acStack_138,"%d",local_1d8[0]);
              }
              else {
                iVar14 = iVar14 + 1;
                sprintf(acStack_138,"%s,%d",acStack_138,*piVar15);
                piVar15 = piVar15 + 1;
              }
            }
            if (wsta_roam_strategy_switch != '\0') {
              printf("[WSTA_ROAM_STRATEGY]%s()/%d   5g_cnt=%d[%s]\n","_roaming_nbr_packet_create",
                     0x3a4,local_254,acStack_138);
            }
            piVar15 = local_1a8;
            iVar14 = 0;
            memset(acStack_138,0,0x100);
            while (iVar14 < local_250) {
              if (iVar14 == 0) {
                iVar14 = 1;
                piVar15 = piVar15 + 1;
                sprintf(acStack_138,"%d",local_1a8[0]);
              }
              else {
                iVar14 = iVar14 + 1;
                sprintf(acStack_138,"%s,%d",acStack_138,*piVar15);
                piVar15 = piVar15 + 1;
              }
            }
            if (wsta_roam_strategy_switch != '\0') {
              printf("[WSTA_ROAM_STRATEGY]%s()/%d \t2g_cnt=%d[%s]\n","_roaming_nbr_packet_create",
                     0x3b2,local_250,acStack_138);
            }
          }
          if (local_250 == 0) {
            if (local_254 != 0) {
              local_16c = *(undefined1 *)(param_5 + 0x17);
              goto LAB_00487bac;
            }
            if (wsta_roam_strategy_switch != '\0') {
              printf("[WSTA_ROAM_STRATEGY]%s()/%d no nbr selected, skip this station.\n",
                     "_roaming_nbr_packet_create",0x3b8);
            }
          }
          else {
            local_16c = *(undefined1 *)(param_5 + 0x17);
LAB_00487bac:
            auStack_174[1] = *(undefined4 *)(param_5 + 0x18);
            memcpy(&uStack_178,(void *)(param_5 + 0xc),6);
            __dest = (void *)(local_23c + local_38 * 0x1c);
            memcpy(__dest,(void *)(param_5 + 0xc),6);
            iVar14 = FUN_004082a0(6,10,0x3d3);
            *(int *)((int)__dest + 0x18) = iVar14;
            if (iVar14 == 0) {
              iVar14 = -1;
              if (wsta_roam_err_switch == '\0') goto LAB_004878a4;
              pcVar12 = "[WSTA_ROAM_ERROR]%s()/%d Out of memory\n";
              uVar13 = 0x3d6;
              goto LAB_004882b8;
            }
            local_2c = local_1d8;
            for (iVar14 = 0; iVar14 < local_254 + local_250; iVar14 = iVar14 + 1) {
              local_258 = 0;
              if (iVar14 < local_254) {
                iVar2 = *local_2c * 0x18 + 0x140;
              }
              else {
                iVar2 = local_1a8[iVar14 - local_254] * 0x18 + 0x20;
              }
              pbVar10 = (byte *)(param_5 + iVar2);
              iVar2 = _ap_union_hash_add(pbVar10,local_34,local_240,&local_244,&local_258);
              if (iVar2 != -1) {
                if (local_258 != 0) {
                  apmngr_db_get_addr_by_capacity
                            (*(undefined2 *)(pbVar10 + 6),param_3,1,1,0x15f0000,1,0x19);
                }
                if (wsta_roam_strategy_switch != '\0') {
                  printf("[WSTA_ROAM_STRATEGY]%s()/%d add ap-mac[%02x:%02x:%02x:%02x:%02x:%02x] to ap union, ret-index=%d, new_added=%d, ap_union_cnt=%u\n"
                         ,"_roaming_nbr_packet_create",0x3ef,(uint)*pbVar10,(uint)pbVar10[1],
                         (uint)pbVar10[2],(uint)pbVar10[3],(uint)pbVar10[4],(uint)pbVar10[5],iVar2,
                         local_258,local_244);
                }
                iVar11 = iVar2 + 7;
                if (-1 < iVar2) {
                  iVar11 = iVar2;
                }
                *(byte *)((int)__dest + (iVar11 >> 3) + 6) =
                     (byte)(1 << (iVar2 % 8 & 0x1fU)) | *(byte *)((int)__dest + (iVar11 >> 3) + 6);
                *(char *)(*(int *)((int)__dest + 0x18) + (uint)*(byte *)((int)__dest + 0x16) * 10) =
                     (char)iVar2;
                *(byte *)(*(int *)((int)__dest + 0x18) + (uint)*(byte *)((int)__dest + 0x16) * 10 +
                         1) = pbVar10[8];
                *(byte *)(*(int *)((int)__dest + 0x18) + (uint)*(byte *)((int)__dest + 0x16) * 10 +
                         2) = pbVar10[0xd];
                memcpy((void *)(*(int *)((int)__dest + 0x18) +
                                (uint)*(byte *)((int)__dest + 0x16) * 10 + 3),pbVar10 + 0xe,6);
                *(byte *)(*(int *)((int)__dest + 0x18) + (uint)*(byte *)((int)__dest + 0x16) * 10 +
                         9) = pbVar10[10];
                *(char *)((int)__dest + 0x16) = *(char *)((int)__dest + 0x16) + '\x01';
                if (local_140 < 4) {
                  iVar2 = local_140 + 3;
                  (&uStack_178)[iVar2 * 4] = *(undefined2 *)(pbVar10 + 6);
                  abStack_176[iVar2 * 8] = pbVar10[8];
                  local_140 = local_140 + 1;
                  abStack_176[iVar2 * 8 + 1] = pbVar10[0xd];
                  auStack_174[iVar2 * 2] = (uint)(iVar14 < local_254);
                }
              }
              local_2c = local_2c + 1;
            }
            *(byte *)((int)__dest + 6) = *(byte *)((int)__dest + 6) | 1;
            if (wsta_roam_strategy_switch != '\0') {
              printf("[WSTA_ROAM_STRATEGY]%s()/%d Add all nbrs into ap_union:\n",
                     "_roaming_nbr_packet_create",0x402);
            }
            for (iVar14 = 0; uVar3 = (uint)*(byte *)(param_5 + 0x1d),
                iVar14 < (int)(uVar3 + *(byte *)(param_5 + 0x1c)); iVar14 = iVar14 + 1) {
              local_258 = 0;
              if (iVar14 < (int)uVar3) {
                iVar2 = iVar14 * 0x18 + 0x140;
              }
              else {
                iVar2 = (iVar14 - uVar3) * 0x18 + 0x20;
              }
              pbVar10 = (byte *)(param_5 + iVar2);
              iVar2 = _ap_union_hash_add(pbVar10,local_34,local_240,&local_244,&local_258);
              if (iVar2 != -1) {
                if (local_258 != 0) {
                  apmngr_db_get_addr_by_capacity
                            (*(undefined2 *)(pbVar10 + 6),param_3,1,1,0x15f0000,1,0x19);
                }
                if (wsta_roam_strategy_switch != '\0') {
                  printf("[WSTA_ROAM_STRATEGY]%s()/%d add ap-mac[%02x:%02x:%02x:%02x:%02x:%02x] to ap union, ret-index=%d, new_added=%d, ap_union_cnt=%u\n"
                         ,"_roaming_nbr_packet_create",0x418,(uint)*pbVar10,(uint)pbVar10[1],
                         (uint)pbVar10[2],(uint)pbVar10[3],(uint)pbVar10[4],(uint)pbVar10[5],iVar2,
                         local_258,local_244);
                }
                iVar11 = iVar2 + 7;
                if (-1 < iVar2) {
                  iVar11 = iVar2;
                }
                *(byte *)((int)__dest + (iVar11 >> 3) + 6) =
                     (byte)(1 << (iVar2 % 8 & 0x1fU)) | *(byte *)((int)__dest + (iVar11 >> 3) + 6);
              }
            }
            if (wsta_roam_strategy_switch != '\0') {
              iVar14 = 0;
              memset(acStack_138,0,0x100);
              do {
                if (iVar14 == 0) {
                  sprintf(acStack_138,"%02x",(uint)*(byte *)((int)__dest + 6));
                }
                else {
                  sprintf(acStack_138,"%s,%02x",acStack_138,
                          (uint)*(byte *)((int)__dest + iVar14 + 6));
                }
                iVar14 = iVar14 + 1;
              } while (iVar14 != 0x10);
              if (wsta_roam_strategy_switch != '\0') {
                printf("[WSTA_ROAM_STRATEGY]%s()/%d ===One station set done, radio_cnt=%u, bitmap[%s]\n"
                       ,"_roaming_nbr_packet_create",0x42c,(uint)*(byte *)((int)__dest + 0x16),
                       acStack_138);
              }
            }
            uVar16 = FUN_004081f0();
            local_168 = uVar16;
            wsta_roam_db_sta_tmprcd_add(&uStack_178);
            local_38 = local_38 + 1;
          }
          param_5 = FUN_00408680(param_5);
        }
        local_248 = local_38;
        if (local_38 == 0) {
          *param_4 = 0;
          if (wsta_roam_strategy_switch != '\0') {
            pcVar12 = 
            "[WSTA_ROAM_STRATEGY]%s()/%d Packet not sent, <<sta_cnt=%u>>, ap_union_cnt=%u\n";
            uVar13 = 0x45f;
            uVar3 = 0;
LAB_004883cc:
            printf(pcVar12,"_roaming_nbr_packet_create",uVar13,uVar3,local_244);
          }
LAB_0048789c:
          iVar14 = 0;
          *param_6 = param_5;
        }
        else {
          iVar14 = cw_service_msg_add(local_30,0x25,&local_238,1,0x59,&local_24c);
          if (iVar14 == 0) {
            iVar14 = capwap_packet_assemble(param_2,local_30);
            if (iVar14 != -1) {
              local_1e8 = 0;
              local_1e0 = 0;
              local_1dc = 1;
              local_1e4 = local_248;
              wsta_roam_db_ap_stats_cumulate(*param_1,auStack_200);
              *param_4 = 1;
              if (wsta_roam_strategy_switch != '\0') {
                pcVar12 = 
                "[WSTA_ROAM_STRATEGY]%s()/%d Packet set done, sta_cnt=%u, ap_union_cnt=%u\n";
                uVar13 = 0x457;
                uVar3 = local_248;
                goto LAB_004883cc;
              }
              goto LAB_0048789c;
            }
            iVar14 = -1;
            if (wsta_roam_err_switch != '\0') {
              pcVar12 = "[WSTA_ROAM_ERROR]%s()/%d capwap_packet_assemble failed\n";
              uVar13 = 0x44a;
              goto LAB_004882b8;
            }
          }
          else {
            iVar14 = -1;
            if (wsta_roam_err_switch != '\0') {
              pcVar12 = "[WSTA_ROAM_ERROR]%s()/%d cw_service_msg_add failed\n";
              uVar13 = 0x443;
              goto LAB_004882b8;
            }
          }
        }
      }
    }
  }
LAB_004878a4:
  cw_parsed_pkt_destroy(local_30);
LAB_004878b0:
  uVar3 = 0;
  FUN_00408310(local_34);
  if (local_23c != 0) {
    while (uVar3 < local_248) {
      iVar2 = uVar3 * 0x1c;
      uVar3 = uVar3 + 1;
      if (*(int *)(local_23c + iVar2 + 0x18) != 0) {
        FUN_00407df0();
      }
    }
    FUN_00407df0();
  }
  if (local_240 != 0) {
    FUN_00407df0();
  }
  uVar13 = 0;
  if (iVar14 != 0) {
    uVar13 = 0xffffffff;
    *param_6 = 0;
  }
  return uVar13;
LAB_00488014:
  bVar1 = *(byte *)(param_5 + 0x1d);
  while( true ) {
    if ((int)(uint)bVar1 <= iVar14) goto LAB_00487a8c;
    if (wsta_roam_strategy_switch == '\0') break;
    pbVar10 = (byte *)(param_5 + iVar14 * 0x18 + 0x140);
    printf("[WSTA_ROAM_STRATEGY]%s()/%d     [idx=%d]channel-load=%u, rssi=%d, estimated_rate=%d, ap-mac=[%02x:%02x:%02x:%02x:%02x:%02x], radio_id=%u, channel=%u, wlan_id=%u, bssid=[%02x:%02x:%02x:%02x:%02x:%02x]\n"
           ,"_roaming_nbr_packet_create",0x38a,iVar14,(uint)pbVar10[9],(int)(char)pbVar10[0xc],
           *(undefined4 *)(pbVar10 + 0x14),(uint)*pbVar10,(uint)pbVar10[1],(uint)pbVar10[2],
           (uint)pbVar10[3],(uint)pbVar10[4],(uint)pbVar10[5],(uint)pbVar10[8],(uint)pbVar10[10],
           (uint)pbVar10[0xd],(uint)pbVar10[0xe],(uint)pbVar10[0xf],(uint)pbVar10[0x10],
           (uint)pbVar10[0x11],(uint)pbVar10[0x12],(uint)pbVar10[0x13]);
    bVar1 = *(byte *)(param_5 + 0x1d);
    iVar14 = iVar14 + 1;
  }
  iVar14 = iVar14 + 1;
  goto LAB_00488014;
}

