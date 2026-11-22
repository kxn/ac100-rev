// func mesh_ap_led_update_test @ 005d2638 size=1

undefined4
mesh_ap_led_update_test
          (undefined4 param_1,undefined2 param_2,char *param_3,char *param_4,int param_5,
          undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  char *__s;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
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
  puVar9 = (undefined4 *)0x0;
  iVar2 = cw_parsed_pkt_create(10);
  if (iVar2 != 0) {
    uRam0074e655 = 0;
    uRam0074e656 = 0x2d;
    puVar9 = (undefined4 *)cw_pkt_buf_create(0x3a);
    if (puVar9 != (undefined4 *)0x0) {
      memcpy((void *)*puVar9,&cw_led_update_req_mesh,0x3a);
      *(undefined2 *)((int)puVar9 + 6) = 0;
      *(undefined2 *)(puVar9 + 1) = 0x3a;
      iVar3 = capwap_packet_parse(puVar9,iVar1,0,0,&uStack_84);
      if (iVar3 == -1) {
        __s = "parse packet failed. \r";
      }
      else {
        *(undefined4 *)(iVar1 + 0x10) = 0xd;
        iVar3 = cw_msg_ele_priv_val_get_from_pkt(iVar1,0x75);
        if ((iVar3 == 0) ||
           (puVar4 = (undefined4 *)cw_priv_mesh_public_control_priv_get(iVar3,0x38),
           puVar4 == (undefined4 *)0x0)) {
          __s = "No mesh public led status val. \r";
        }
        else {
          iVar5 = sscanf(param_4,"%2X-%2X-%2X-%2X-%2X-%2X",&uStack_74,auStack_70,auStack_6c,
                         auStack_68,auStack_64,auStack_60);
          if (iVar5 == 6) {
            puVar10 = &uStack_74;
            iVar5 = 0;
            puVar6 = puVar10;
            do {
              uVar8 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = (undefined1 *)(*(int *)(iVar3 + 4) + iVar5);
              iVar5 = iVar5 + 1;
              *puVar7 = (char)uVar8;
            } while (iVar5 != 6);
            iVar5 = sscanf(param_3,"%2X-%2X-%2X-%2X-%2X-%2X",&uStack_74,auStack_70,auStack_6c,
                           auStack_68,auStack_64,auStack_60);
            if (iVar5 == 6) {
              iVar5 = 0;
              do {
                puVar7 = auStack_5c + iVar5;
                uVar8 = *puVar10;
                iVar5 = iVar5 + 1;
                puVar10 = puVar10 + 1;
                *puVar7 = (char)uVar8;
              } while (iVar5 != 6);
              uStack_4c = 1;
              *puVar4 = param_6;
              uStack_48 = param_1;
              uStack_38 = param_2;
              for (iVar5 = 0; iVar5 < param_5; iVar5 = iVar5 + 1) {
                serv_mngr_handle(iVar1,auStack_5c,iVar2);
                *(char *)(*(int *)(iVar3 + 4) + 5) = *(char *)(*(int *)(iVar3 + 4) + 5) + '\x01';
              }
              goto code_r0x005d2820;
            }
          }
          __s = "parameter is wrong";
        }
      }
      puts(__s);
    }
  }
code_r0x005d2820:
  cw_parsed_pkt_destroy(iVar1);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (puVar9 != (undefined4 *)0x0) {
    cw_pkt_buf_destroy(puVar9);
  }
  return 0;
}

