// func _radius_send_to_server @ 0043e038 size=5404

/* WARNING: Type propagation algorithm not settling */

int _radius_send_to_server(int *param_1,undefined4 *param_2,undefined1 *param_3,int *param_4)

{
  char cVar1;
  undefined *puVar2;
  addrinfo *paVar3;
  int iVar4;
  undefined1 *puVar5;
  size_t sVar6;
  int iVar7;
  ssize_t sVar8;
  int extraout_v1;
  char *pcVar9;
  uchar *__src;
  undefined4 uVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  char *__name;
  size_t __n;
  undefined8 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 local_580;
  undefined4 local_57c;
  uint local_578;
  int local_574;
  uint local_570 [3];
  addrinfo *local_564;
  undefined4 local_560;
  undefined4 local_55c;
  int local_558;
  undefined4 local_554;
  char local_550 [12];
  undefined4 local_544;
  undefined4 local_540;
  undefined4 local_53c;
  undefined4 local_538;
  undefined4 local_534;
  undefined4 local_530;
  undefined4 local_52c;
  undefined4 local_528;
  undefined4 local_524;
  undefined4 local_520;
  undefined4 local_51c;
  undefined4 local_518;
  undefined4 local_514;
  undefined4 local_510;
  undefined4 local_50c;
  undefined4 local_508;
  undefined1 local_504;
  undefined4 local_500;
  undefined4 local_4fc;
  undefined4 local_4f8;
  undefined4 local_4f4;
  undefined4 local_4f0;
  undefined4 local_4ec;
  undefined4 local_4e8;
  undefined4 local_4e4;
  undefined4 local_4e0;
  undefined4 local_4dc;
  undefined4 local_4d8;
  undefined4 local_4d4;
  undefined4 local_4d0;
  undefined4 local_4cc;
  undefined4 local_4c8;
  char local_4c4 [20];
  addrinfo aStack_4b0;
  undefined1 auStack_490 [40];
  undefined4 local_468;
  undefined4 local_464;
  char acStack_434 [52];
  char local_400;
  char local_3ff;
  undefined4 auStack_3fe [6];
  undefined1 auStack_3e6 [26];
  MD5_CTX MStack_3cc;
  char acStack_364 [200];
  uchar auStack_29c [276];
  undefined1 auStack_188 [352];
  
  iVar13 = -1;
  local_550[0] = '\0';
  local_550[1] = '\0';
  local_550[2] = '\0';
  local_550[3] = '\0';
  local_550[4] = '\0';
  local_550[5] = '\0';
  local_550[6] = '\0';
  local_550[7] = '\0';
  local_550[8] = '\0';
  local_550[9] = '\0';
  local_524 = 0;
  local_520 = 0;
  local_51c = 0;
  local_518 = 0;
  local_534 = 0;
  local_530 = 0;
  local_52c = 0;
  local_528 = 0;
  local_544 = 0;
  local_540 = 0;
  local_53c = 0;
  local_538 = 0;
  local_514 = 0;
  local_510 = 0;
  local_50c = 0;
  local_508 = 0;
  local_504 = 0;
  memset(&local_400,0,0x32);
  memset(auStack_29c,0,0x114);
  memset(acStack_434,0,0x32);
  local_4c4[0] = '\0';
  local_4c4[1] = '\0';
  local_4c4[2] = '\0';
  local_4c4[3] = '\0';
  local_4c4[4] = '\0';
  local_4c4[5] = '\0';
  local_4c4[6] = '\0';
  local_4c4[7] = '\0';
  local_4c4[8] = '\0';
  local_4c4[9] = '\0';
  local_4c4[10] = '\0';
  local_4c4[0xb] = '\0';
  local_4c4[0xc] = '\0';
  local_4c4[0xd] = '\0';
  local_4c4[0xe] = '\0';
  local_4c4[0xf] = '\0';
  local_4c4[0x10] = '\0';
  local_4c4[0x11] = '\0';
  local_4c4[0x12] = '\0';
  local_4c4[0x13] = '\0';
  memset(acStack_364,0,200);
  local_564 = (addrinfo *)0x0;
  local_4d8 = 0;
  local_4d4 = 0;
  local_4d0 = 0;
  local_4cc = 0;
  local_4c8 = 0;
  local_570[2] = 0;
  local_570[1] = 1;
  local_4ec = 0;
  local_4e8 = 0;
  local_4e4 = 0;
  local_4e0 = 0;
  local_4dc = 0;
  local_570[0] = 0;
  if (param_2 == (undefined4 *)0x0) {
    return -1;
  }
  if (param_3 == (undefined1 *)0x0) {
    return -1;
  }
  if (param_4 == (int *)0x0) {
    return -1;
  }
  __name = (char *)*param_2;
  puVar5 = (undefined1 *)0x0;
  if (__name == (char *)0x0) goto LAB_0043e310;
  memset(&aStack_4b0,0,0x20);
  cVar1 = *(char *)((int)param_2 + 0x62a);
  aStack_4b0.ai_socktype = 1;
  if (((cVar1 == '\x04') || (cVar1 == '\x06')) || (cVar1 == '\n')) {
    uVar10 = *(undefined4 *)(__name + 0x200);
  }
  else {
    uVar10 = *(undefined4 *)(__name + 0x1fc);
  }
  sprintf(local_550,"%d",uVar10);
  if (radius_info_switch != 0) {
    printf("[RADIUS_INFO]%s()/%d Start dns: %s\n","_radius_send_to_server",0x463,__name);
  }
  iVar13 = getaddrinfo(__name,local_550,&aStack_4b0,&local_564);
  paVar3 = local_564;
  if ((iVar13 == 0) && (local_564 != (addrinfo *)0x0)) {
    if (local_564->ai_family == 2) {
      if (radius_info_switch != 0) {
        uVar10 = 0x470;
        puVar5 = *(undefined1 **)(local_564->ai_addr->sa_data + 2);
        pcVar9 = "[RADIUS_INFO]%s()/%d Query dns for %s, result: %x\n";
LAB_0043ea20:
        printf(pcVar9,"_radius_send_to_server",uVar10,__name,puVar5);
      }
    }
    else if (local_564->ai_family == 10) {
      local_500 = 0;
      local_4fc = 0;
      local_4f8 = 0;
      local_4f4 = 0;
      local_4f0 = 0;
      memset(auStack_490,0,0x28);
      local_500 = CONCAT13(2,local_500._1_3_);
      memcpy(&local_4fc,paVar3->ai_addr->sa_data + 6,0x10);
      uac_ipaddr_convert_binary2str
                (local_500,local_4fc,local_4f8,local_4f4,local_4f0,auStack_490,0x28,"---");
      if (radius_info_switch != 0) {
        puVar5 = auStack_490;
        uVar10 = 0x47b;
        pcVar9 = "[RADIUS_INFO]%s()/%d Query dns for %s, result: %s\n";
        goto LAB_0043ea20;
      }
    }
    if (local_564->ai_family == 2) {
      local_4d8 = CONCAT13(1,local_4d8._1_3_);
      local_4d4 = *(undefined4 *)(local_564->ai_addr->sa_data + 2);
    }
    else if (local_564->ai_family == 10) {
      local_4d8 = CONCAT13(2,local_4d8._1_3_);
      memcpy(&local_4d4,local_564->ai_addr->sa_data + 6,0x10);
    }
    pcVar9 = (char *)(param_2 + 0x107);
    wportal_radius_server_table_add
              (*(undefined4 *)(__name + 0x208),local_4d8,local_4d4,local_4d0,local_4cc,local_4c8);
    iVar13 = radius_pair_add(rh,local_570 + 2,1,pcVar9,0xffffffff,0);
    if (iVar13 != 0) {
      cVar1 = *(char *)((int)param_2 + 0x62a);
      if ((int)cVar1 == 1) {
        uVar12 = *(uint *)(__name + 500);
        if (uVar12 == 2) {
          local_570[0] = uVar12;
          iVar13 = radius_pair_add(rh,local_570 + 2,6,local_570,0xffffffff,0);
          if ((iVar13 != 0) &&
             (local_570[0] = (int)cVar1,
             iVar13 = radius_pair_add(rh,local_570 + 2,7,local_570,0xffffffff,0), iVar13 != 0)) {
            if ((*(byte *)(param_2 + 0x18b) & 1) == 0) {
              _radius_random_vector(&local_534);
              iVar13 = radius_pair_add(rh,local_570 + 2,0x3c,&local_534,0x10,0);
              if (iVar13 != 0) {
                MD5_Init(&MStack_3cc);
                puVar2 = PTR_DAT_007591ac;
                MD5_Update(&MStack_3cc,PTR_DAT_007591ac + 0x12a0,1);
                sVar6 = strlen((char *)((int)param_2 + 0x481));
                MD5_Update(&MStack_3cc,(char *)((int)param_2 + 0x481),sVar6);
                MD5_Update(&MStack_3cc,&local_534,0x10);
                MD5_Final(auStack_29c,&MStack_3cc);
                cVar1 = puVar2[0x12a0];
                __src = auStack_29c;
                local_514 = CONCAT13(cVar1,local_514._1_3_);
                puVar2[0x12a0] = cVar1 + '\x01';
                goto LAB_0043eb78;
              }
            }
            else {
              iVar13 = radius_pair_add(rh,local_570 + 2,0x3c,(int)param_2 + 0x4f6,0x10,0);
              if (iVar13 != 0) {
                __src = (uchar *)((int)param_2 + 0x481);
                local_514 = CONCAT13(*(undefined1 *)(param_2 + 0x18a),local_514._1_3_);
LAB_0043eb78:
                memcpy((void *)((int)&local_514 + 1),__src,0x10);
                uVar10 = 3;
                uVar15 = 0x11;
                puVar11 = &local_514;
                uVar16 = 0;
                goto LAB_0043e508;
              }
            }
          }
        }
        else if (uVar12 < 3) {
          if (uVar12 != 1) {
            iVar4 = param_2[0x15a];
            goto LAB_0043e2f4;
          }
          iVar13 = radius_pair_add(rh,local_570 + 2,2,(int)param_2 + 0x481,0xffffffff,0);
          if (iVar13 != 0) {
            local_570[0] = 2;
            iVar13 = radius_pair_add(rh,local_570 + 2,6,local_570,0xffffffff,0);
            if (iVar13 != 0) {
              uVar10 = 7;
              puVar11 = local_570;
              uVar15 = 0xffffffff;
              uVar16 = 0;
              local_570[0] = uVar12;
              goto LAB_0043e508;
            }
          }
        }
        else if (uVar12 == 3) {
          _radius_random_vector(&local_534);
          iVar13 = radius_pair_add(rh,local_570 + 2,0xb,&local_534,8,0x137);
          if (iVar13 != 0) {
            local_400 = PTR_DAT_007591ac[0x12a0] + '\x01';
            PTR_DAT_007591ac[0x12a0] = local_400;
            local_3ff = cVar1;
            sVar6 = strlen((char *)((int)param_2 + 0x481));
            _ntPasswordHash((char *)((int)param_2 + 0x481),sVar6,auStack_490);
            _challengeResponse(&local_534,auStack_490,auStack_3e6);
            uVar10 = 1;
            uVar15 = 0x32;
            puVar11 = (uint *)&local_400;
            uVar16 = 0x137;
LAB_0043e508:
            iVar13 = radius_pair_add(rh,local_570 + 2,uVar10,puVar11,uVar15,uVar16);
            if (iVar13 != 0) goto LAB_0043e2f0;
          }
        }
        else {
          if (uVar12 != 4) {
            iVar4 = param_2[0x15a];
            goto LAB_0043e2f4;
          }
          _radius_random_vector(&local_534);
          iVar13 = radius_pair_add(rh,local_570 + 2,0xb,&local_534,0x10,0x137);
          if (iVar13 != 0) {
            _radius_random_vector(&local_544);
            local_3ff = '\0';
            local_400 = PTR_DAT_007591ac[0x12a0] + '\x01';
            PTR_DAT_007591ac[0x12a0] = local_400;
            memcpy(auStack_3fe,&local_544,0x10);
            shaInit(auStack_188);
            shaUpdate(auStack_188,&local_544,0x10);
            shaUpdate(auStack_188,&local_534,0x10);
            sVar6 = strlen(pcVar9);
            shaUpdate(auStack_188,pcVar9,sVar6);
            shaFinal(auStack_188,&local_468);
            local_560 = local_468;
            local_55c = local_464;
            sVar6 = strlen((char *)((int)param_2 + 0x481));
            _ntPasswordHash((char *)((int)param_2 + 0x481),sVar6,auStack_490);
            _challengeResponse(&local_560,auStack_490,auStack_3e6);
            uVar10 = 0x19;
            uVar15 = 0x32;
            puVar11 = (uint *)&local_400;
            uVar16 = 0x137;
            goto LAB_0043e508;
          }
        }
      }
      else {
LAB_0043e2f0:
        iVar4 = param_2[0x15a];
LAB_0043e2f4:
        iVar13 = 0;
        if (iVar4 == 0 && param_2[0x15b] == 0) {
          puVar5 = (undefined1 *)0x0;
          if (radius_debug_switch != 0) {
            printf("[RADIUS_DEBUG]%s()/%d sessid is 0\n","_radius_send_to_server",0x52a);
          }
          goto LAB_0043e310;
        }
        sprintf(local_4c4,"%02x%02x%02x%02x%02x%02x",(uint)*(byte *)((int)param_2 + 0x547),
                (uint)*(byte *)(param_2 + 0x152),(uint)*(byte *)((int)param_2 + 0x549),
                (uint)*(byte *)((int)param_2 + 0x54a),(uint)*(byte *)((int)param_2 + 0x54b),
                (uint)*(byte *)(param_2 + 0x153));
        sprintf(acStack_364,"%s-%llu",local_4c4);
        iVar4 = radius_pair_add(rh,local_570 + 2,0x2c,acStack_364,0xffffffff,0);
        if (iVar4 != 0) {
          if (*(char *)((int)param_2 + 0x62a) == '\x04') {
            local_57c = 0;
            local_580 = 0;
            iVar4 = radius_pair_add(rh,local_570 + 2,0x28,param_2 + 0x17f,0,0);
            if ((iVar4 != 0) &&
               (iVar4 = radius_pair_add(rh,local_570 + 2,0x29,&local_57c,0,0), iVar4 != 0)) {
              local_580 = 1;
              iVar4 = radius_pair_add(rh,local_570 + 2,0x2d,&local_580,0,0);
              if (iVar4 != 0) {
                if (1 < param_2[0x17f] - 2) {
LAB_0043ec40:
                  if ((param_2[0x17f] == 2) &&
                     (iVar4 = radius_pair_add(rh,local_570 + 2,0x31,param_2 + 0x180,0,0), iVar4 == 0
                     )) {
                    iVar13 = -1;
                    puVar5 = (undefined1 *)0x0;
                    goto LAB_0043e310;
                  }
                  goto LAB_0043e5d4;
                }
                iVar4 = radius_pair_add(rh,local_570 + 2,0x2e,param_2 + 0x17c,0,0);
                if (iVar4 != 0) {
                  local_574 = param_2[0x18d] << 10;
                  local_578 = param_2[0x18c] << 10 | (uint)param_2[0x18d] >> 0x16;
                  iVar4 = radius_pair_add(rh,local_570 + 2,0x2a,&local_574,0,0);
                  if ((iVar4 != 0) &&
                     (iVar4 = radius_pair_add(rh,local_570 + 2,0x34,&local_578,0,0), iVar4 != 0)) {
                    local_574 = param_2[399] << 10;
                    local_578 = param_2[0x18e] << 10 | (uint)param_2[399] >> 0x16;
                    iVar4 = radius_pair_add(rh,local_570 + 2,0x2b,&local_574,0,0);
                    if ((iVar4 != 0) &&
                       (iVar4 = radius_pair_add(rh,local_570 + 2,0x35,&local_578,0,0), iVar4 != 0))
                    {
                      local_580 = 0;
                      iVar4 = radius_pair_add(rh,local_570 + 2,0x2f,&local_580,0,0);
                      if (iVar4 != 0) {
                        local_580 = 0;
                        iVar4 = radius_pair_add(rh,local_570 + 2,0x30,&local_580,0,0);
                        if (iVar4 == 0) {
                          iVar13 = -1;
                          puVar5 = (undefined1 *)0x0;
                          goto LAB_0043e310;
                        }
                        goto LAB_0043ec40;
                      }
                    }
                  }
                }
              }
            }
          }
          else {
LAB_0043e5d4:
            pcVar9 = __name + 0x178;
            if (__name[0x178] == '\0') {
              pcVar9 = &default_nas_identifier;
            }
            iVar4 = radius_pair_add(rh,local_570 + 2,0x20,pcVar9,0xffffffff,0);
            if (iVar4 != 0) {
              sprintf(local_4c4,"%02x-%02x-%02x-%02x-%02x-%02x",
                      (uint)*(byte *)((int)param_2 + 0x547),(uint)*(byte *)(param_2 + 0x152),
                      (uint)*(byte *)((int)param_2 + 0x549),(uint)*(byte *)((int)param_2 + 0x54a),
                      (uint)*(byte *)((int)param_2 + 0x54b),(uint)*(byte *)(param_2 + 0x153));
              iVar4 = radius_pair_add(rh,local_570 + 2,0x1f,local_4c4,0xffffffff,0);
              if (iVar4 != 0) {
                local_4c4[0] = '\0';
                local_4c4[1] = '\0';
                local_4c4[2] = '\0';
                local_4c4[3] = '\0';
                local_4c4[4] = '\0';
                local_4c4[5] = '\0';
                local_4c4[6] = '\0';
                local_4c4[7] = '\0';
                local_4c4[8] = '\0';
                local_4c4[9] = '\0';
                local_4c4[10] = '\0';
                local_4c4[0xb] = '\0';
                local_4c4[0xc] = '\0';
                local_4c4[0xd] = '\0';
                local_4c4[0xe] = '\0';
                local_4c4[0xf] = '\0';
                local_4c4[0x10] = '\0';
                local_4c4[0x11] = '\0';
                local_4c4[0x12] = '\0';
                local_4c4[0x13] = '\0';
                if (((param_2[0x153] & 0xffffff) == 0) && ((param_2[0x154] & 0xffffff00) == 0)) {
                  strcpy(local_4c4,&device_mac);
                }
                else {
                  sprintf(local_4c4,"%02x-%02x-%02x-%02x-%02x-%02x",
                          (uint)*(byte *)((int)param_2 + 0x54d),
                          (uint)*(byte *)((int)param_2 + 0x54e),
                          (uint)*(byte *)((int)param_2 + 0x54f),(uint)*(byte *)(param_2 + 0x154),
                          (uint)*(byte *)((int)param_2 + 0x551),
                          (uint)*(byte *)((int)param_2 + 0x552));
                }
                iVar4 = radius_pair_add(rh,local_570 + 2,0x1e,local_4c4,0xffffffff,0);
                if (iVar4 != 0) {
                  if (*(char *)(param_2 + 0x15f) == '\x01') {
                    local_4e8 = param_2[0x160];
                    iVar4 = radius_pair_add(rh,local_570 + 2,8,&local_4e8,0xffffffff,0);
                    if (iVar4 == 0) {
                      iVar13 = -1;
                      puVar5 = (undefined1 *)0x0;
                      goto LAB_0043e310;
                    }
                  }
                  if ((__name[0x1e0] == '\x01') &&
                     (iVar4 = uac_ipaddr_is_not_empty
                                        (*(undefined4 *)(__name + 0x1e0),
                                         *(undefined4 *)(__name + 0x1e4),
                                         *(undefined4 *)(__name + 0x1e8),
                                         *(undefined4 *)(__name + 0x1ec),
                                         *(undefined4 *)(__name + 0x1f0)), iVar4 != 0)) {
                    local_4e8 = *(undefined4 *)(__name + 0x1e4);
                    uVar10 = 4;
LAB_0043f078:
                    iVar4 = radius_pair_add(rh,local_570 + 2,uVar10,&local_4e8,0xffffffff,0);
                    if (iVar4 == 0) {
                      iVar13 = -1;
                      puVar5 = (undefined1 *)0x0;
                      goto LAB_0043e310;
                    }
                  }
                  else if ((__name[0x1e0] == '\x02') &&
                          (iVar4 = uac_ipaddr_is_not_empty
                                             (*(undefined4 *)(__name + 0x1e0),
                                              *(undefined4 *)(__name + 0x1e4),
                                              *(undefined4 *)(__name + 0x1e8),
                                              *(undefined4 *)(__name + 0x1ec),
                                              *(undefined4 *)(__name + 0x1f0)), iVar4 != 0)) {
                    memcpy(&local_4e8,__name + 0x1e4,0x10);
                    uVar10 = 0x5f;
                    goto LAB_0043f078;
                  }
                  iVar4 = radius_pair_add(rh,local_570 + 2,5,param_2 + 0x182,0xffffffff,0);
                  if (iVar4 != 0) {
                    uVar12 = 0xf;
                    if ((*(byte *)(param_2 + 0x18b) & 4) == 0) {
                      if ((*(char *)((int)param_2 + 0x553) == '\0') &&
                         (iVar4 = wportal_get_mode(), iVar4 != 2)) {
                        uVar12 = 0x13;
                      }
                      else {
                        uVar12 = 0xf;
                      }
                    }
                    local_570[0] = uVar12;
                    iVar4 = radius_pair_add(rh,local_570 + 2,0x3d,local_570,0xffffffff,0);
                    if (iVar4 != 0) {
                      strcpy(acStack_434,"lan");
                      iVar4 = radius_pair_add(rh,local_570 + 2,0x57,acStack_434,0xffffffff,0);
                      if (iVar4 != 0) {
                        *param_3 = *(undefined1 *)((int)param_2 + 0x62a);
                        seq_number = seq_number + 1;
                        param_3[1] = (char)seq_number;
                        if (*(char *)((int)param_2 + 0x62a) == '\x04') {
                          pcVar9 = __name + 0xff;
                          iVar4 = _radius_pack_list(local_570[2],pcVar9,param_3);
                          __n = iVar4 + 0x14;
                          *(short *)(param_3 + 2) = (short)__n;
                          memset(param_3 + 4,0,0x10);
                          sVar6 = strlen(pcVar9);
                          memcpy(param_3 + __n,pcVar9,sVar6);
                          _ac_md5_calc(&local_524,param_3,__n + sVar6);
                          memcpy(param_3 + 4,&local_524,0x10);
                        }
                        else {
                          _radius_random_vector(&local_524);
                          memcpy(param_3 + 4,&local_524,0x10);
                          iVar4 = _radius_pack_list(local_570[2],__name + 0xff,param_3);
                          __n = iVar4 + 0x14;
                          *(short *)(param_3 + 2) = (short)__n;
                        }
                        puVar5 = param_3;
                        if (param_1 == (int *)0x0) {
                          iVar4 = 2;
                          if (local_564->ai_family != 2) {
                            iVar4 = 10;
                          }
                          iVar4 = socket(iVar4,1,0);
                          if (iVar4 < 0) {
                            if (radius_debug_switch != 0) {
                              printf("[RADIUS_DEBUG]%s()/%d Create radius socket error\n\n",
                                     "_radius_send_to_server",0x64e);
                            }
                          }
                          else {
                            _radius_setnonblocking(iVar4);
                            local_570[1] = 0x800;
                            iVar7 = setsockopt(iVar4,0xffff,0x1002,local_570 + 1,4);
                            if (iVar7 == -1) {
                              if (radius_debug_switch != 0) {
                                uVar10 = 0x663;
                                pcVar9 = 
                                "[RADIUS_DEBUG]%s()/%d setsockopt radius socket SO_RCVBUF error\n\n"
                                ;
LAB_0043f470:
                                printf(pcVar9,"_radius_send_to_server",uVar10);
                              }
                            }
                            else {
                              local_570[1] = 0x800;
                              iVar7 = setsockopt(iVar4,0xffff,0x1001,local_570 + 1,4);
                              if (iVar7 == -1) {
                                if (radius_debug_switch != 0) {
                                  uVar10 = 0x66c;
                                  pcVar9 = 
                                  "[RADIUS_DEBUG]%s()/%d setsockopt radius socket SO_SNDBUF error\n\n"
                                  ;
                                  goto LAB_0043f470;
                                }
                              }
                              else if (local_564->ai_family == 2) {
                                sVar8 = sendto(iVar4,param_3,__n,0,local_564->ai_addr,0x10);
                                if (-1 < sVar8) {
LAB_0043f43c:
                                  *param_4 = iVar4;
                                  goto LAB_0043e310;
                                }
                                if (radius_debug_switch != 0) {
                                  uVar10 = 0x677;
                                  pcVar9 = "[RADIUS_DEBUG]%s()/%d Send error\n";
                                  goto LAB_0043f470;
                                }
                              }
                              else {
                                if ((local_564->ai_family != 10) ||
                                   (sVar8 = sendto(iVar4,param_3,__n,0,local_564->ai_addr,0x1c),
                                   -1 < sVar8)) goto LAB_0043f43c;
                                if (radius_debug_switch != 0) {
                                  uVar10 = 0x683;
                                  pcVar9 = "[RADIUS_DEBUG]%s()/%d Send error\n";
                                  goto LAB_0043f470;
                                }
                              }
                            }
                            close(iVar4);
                          }
                          iVar13 = -1;
                          goto LAB_0043e310;
                        }
                        if (local_564->ai_family == 2) {
                          sVar8 = sendto(*param_1,param_3,__n,0,local_564->ai_addr,0x10);
                          if (sVar8 < 0) {
                            if (radius_debug_switch != 0) {
                              uVar10 = 0x693;
LAB_0043f244:
                              printf("[RADIUS_DEBUG]%s()/%d Send error\n","_radius_send_to_server",
                                     uVar10);
                            }
LAB_0043f1dc:
                            iVar13 = -1;
                            *param_4 = -1;
                            goto LAB_0043e310;
                          }
                        }
                        else if ((local_564->ai_family == 10) &&
                                (sVar8 = sendto(param_1[1],param_3,__n,0,local_564->ai_addr,0x1c),
                                sVar8 < 0)) {
                          if (radius_debug_switch != 0) {
                            uVar10 = 0x69e;
                            goto LAB_0043f244;
                          }
                          goto LAB_0043f1dc;
                        }
                        *param_4 = -1;
                        goto LAB_0043e310;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if (radius_debug_switch != 0) {
    pcVar9 = gai_strerror(iVar13);
    printf("[RADIUS_DEBUG]%s()/%d DNS query failed: %d err: %s\n","_radius_send_to_server",0x469,
           iVar13,pcVar9);
  }
  iVar13 = -1;
  puVar5 = (undefined1 *)0x0;
LAB_0043e310:
  param_2[0x17b] = param_2[0x17b] + 1;
  if (iVar13 == 0) {
    param_2[0x17e] = (uint)(byte)puVar5[1];
  }
  local_558 = 0;
  local_554 = 0;
  uVar14 = uac_time_usecs();
  __udivdi3((int)((ulonglong)uVar14 >> 0x20),(int)uVar14,0,1000000);
  local_558 = *(int *)(__name + 0x1f8) + extraout_v1;
  param_2[0x169] = local_558;
  param_2[0x16a] = local_554;
  memcpy((void *)((int)param_2 + 0x4e6),&local_524,0x10);
  if ((*(byte *)(param_2 + 0x18b) & 1) == 0) {
    memcpy((void *)((int)param_2 + 0x4f6),&local_534,0x10);
  }
  if (local_564 != (addrinfo *)0x0) {
    freeaddrinfo(local_564);
  }
  if (local_570[2] != 0) {
    radius_pair_free();
  }
  return iVar13;
}

