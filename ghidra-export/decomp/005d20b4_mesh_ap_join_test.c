// func mesh_ap_join_test @ 005d20b4 size=1

undefined4
mesh_ap_join_test(undefined4 param_1,undefined2 param_2,char *param_3,char *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  char *__s;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [4];
  undefined1 auStack_60 [4];
  undefined1 auStack_5c [16];
  undefined1 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_38;
  
  memset(auStack_5c,0,0x34);
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  iVar1 = cw_parsed_pkt_create(9);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = cw_parsed_pkt_create(10);
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    uRam0074e6e1 = 1;
    uRam0074e6e2 = 0xb1;
    puVar3 = (undefined4 *)cw_pkt_buf_create(0x1be);
    if (puVar3 != (undefined4 *)0x0) {
      memcpy((void *)*puVar3,&cw_join_req_mesh,0x1be);
      *(undefined2 *)((int)puVar3 + 6) = 0;
      *(undefined2 *)(puVar3 + 1) = 0x1be;
      iVar4 = capwap_packet_parse(puVar3,iVar1,0,0,&uStack_84);
      if (iVar4 == -1) {
        __s = "parse packet failed. \r";
      }
      else {
        iVar4 = cw_msg_ele_priv_val_get_from_pkt(iVar1,0x76);
        if ((iVar4 == 0) ||
           (puVar5 = (undefined1 *)cw_priv_mesh_private_control_get(iVar4,4),
           puVar5 == (undefined1 *)0x0)) {
          __s = "No mesh private join request val. \r";
        }
        else {
          puVar9 = &uStack_74;
          iVar4 = sscanf(param_4,"%2X-%2X-%2X-%2X-%2X-%2X",puVar9,auStack_70,auStack_6c,auStack_68,
                         auStack_64,auStack_60);
          if (iVar4 != 6) {
            puts("parameter is wrong");
            return 0;
          }
          iVar4 = 0;
          puVar6 = puVar5;
          do {
            puVar7 = (undefined4 *)((int)puVar9 + iVar4);
            iVar4 = iVar4 + 4;
            *puVar6 = (char)*puVar7;
            puVar6 = puVar6 + 1;
          } while (iVar4 != 0x18);
          iVar4 = sscanf(param_3,"%2X-%2X-%2X-%2X-%2X-%2X",puVar9,auStack_70,auStack_6c,auStack_68,
                         auStack_64,auStack_60);
          if (iVar4 == 6) {
            iVar4 = 0;
            do {
              puVar6 = auStack_5c + iVar4;
              uVar8 = *puVar9;
              iVar4 = iVar4 + 1;
              puVar9 = puVar9 + 1;
              *puVar6 = (char)uVar8;
            } while (iVar4 != 6);
            uStack_4c = 1;
            uStack_48 = param_1;
            uStack_38 = param_2;
            for (iVar4 = 0; iVar4 < param_5; iVar4 = iVar4 + 1) {
              serv_mngr_handle(iVar1,auStack_5c,iVar2);
              puVar5[5] = puVar5[5] + '\x01';
            }
            goto code_r0x005d2284;
          }
          __s = "parameter is wrong";
        }
      }
      puts(__s);
    }
  }
code_r0x005d2284:
  cw_parsed_pkt_destroy(iVar1);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (puVar3 != (undefined4 *)0x0) {
    cw_pkt_buf_destroy(puVar3);
  }
  return 0;
}

