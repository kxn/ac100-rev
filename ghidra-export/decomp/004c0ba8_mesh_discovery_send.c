// func mesh_discovery_send @ 004c0ba8 size=912

int mesh_discovery_send(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_98 [4];
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 auStack_64 [68];
  
  iVar3 = -1;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  memset(auStack_64,0,0x40);
  if ((param_1 != 0) && (iVar3 = -1, param_2 != (int *)0x0)) {
    iVar3 = 0;
    iVar1 = ap_mesh_switch_is_enable(*(undefined2 *)(param_1 + 0x10));
    if (iVar1 != 0) {
      local_88 = 0;
      local_84 = 0;
      local_80 = 0;
      local_7c = 0;
      *param_2 = *param_2 + 1;
      FUN_00408190(*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
                   *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
                   *(undefined4 *)(param_1 + 0x27c),auStack_64,0x40,"---");
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d Send mesh switch packet to update AP(ip:%s, port:%d)\'s config.\n"
               ,"mesh_discovery_send",0x7a8,auStack_64,(uint)*(ushort *)(param_1 + 0x280));
      }
      iVar1 = 0;
      iVar3 = serv_wtp_address_arg_init(&local_88);
      if ((iVar3 == 0) &&
         (iVar3 = apmngr_db_get_addr_by_capacity
                            (*(undefined2 *)(param_1 + 0x10),&local_88,1,1,0xe0000,1,0x2c),
         iVar3 == 0)) {
        if (local_80 == 0) {
          if (mesh_debug_switch != '\0') {
            printf("[MESH_DEBUG]%s()/%d No need to send for AP %d.\n","mesh_discovery_send",0x7ba,
                   (uint)*(ushort *)(param_1 + 0x10));
          }
        }
        else {
          iVar3 = -1;
          iVar1 = cw_pkt_buf_create(0xfa);
          if (iVar1 != 0) {
            iVar4 = param_2[1];
            local_78 = 0;
            local_74 = 0;
            local_70 = 0;
            local_6c = 0;
            local_68 = 0;
            local_94 = 0;
            local_90 = 0;
            local_8c = 0;
            local_98[0] = 0;
            if (mesh_debug_switch != '\0') {
              printf("[MESH_DEBUG]%s()/%d Send mesh switch packet to update AP(ip:%d)begin.\n",
                     "_mesh_discovery_req_pkt_create",0x76c,(uint)*(ushort *)(param_1 + 0x10));
            }
            local_78 = 0;
            local_74 = 0;
            iVar3 = -1;
            local_70 = 0;
            local_6c = 0;
            local_68 = 0;
            local_94 = 0;
            local_90 = 0;
            local_8c = 0;
            local_98[0] = 0;
            iVar2 = cw_parsed_pkt_create(7);
            if (iVar2 != 0) {
              if (mesh_debug_switch != '\0') {
                printf("[MESH_DEBUG]%s()/%d create pkt ok.\n","_mesh_discovery_req_pkt_create",0x776
                      );
              }
              FUN_0051ad88(&local_70);
              iVar3 = -1;
              FUN_0051ad88(&local_94);
              local_98[0] = (undefined1)iVar4;
              iVar4 = cw_priv_mesh_private_control_add(&local_94,0,local_98);
              if ((iVar4 == 0) &&
                 (iVar4 = cw_service_msg_add(iVar2,0x25,&local_78,1,0x76,&local_94), iVar4 == 0)) {
                if (mesh_debug_switch != '\0') {
                  printf("[MESH_DEBUG]%s()/%d add pkt ok.\n","_mesh_discovery_req_pkt_create",0x781)
                  ;
                }
                iVar3 = capwap_packet_assemble(iVar1,iVar2);
              }
              cw_parsed_pkt_destroy(iVar2);
              if (mesh_debug_switch != '\0') {
                printf("[MESH_DEBUG]%s()/%d Send mesh switch packet to update AP(ip:%d)finish.\n",
                       "_mesh_discovery_req_pkt_create",0x78a,(uint)*(ushort *)(param_1 + 0x10));
              }
              if (iVar3 == 0) {
                iVar3 = serv_packet_send(&local_88,iVar1,1);
              }
            }
          }
        }
      }
      serv_wtp_address_arg_destroy(&local_88);
      if (iVar1 != 0) {
        cw_pkt_buf_destroy(iVar1);
      }
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d ret %d.\n","mesh_discovery_send",0x7da,iVar3);
      }
    }
  }
  return iVar3;
}

