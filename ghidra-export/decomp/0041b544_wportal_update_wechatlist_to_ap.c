// func wportal_update_wechatlist_to_ap @ 0041b544 size=424

undefined4 wportal_update_wechatlist_to_ap(void *param_1,size_t param_2)

{
  void *__s;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  size_t local_48;
  void *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_48 = 0;
  local_44 = (void *)0x0;
  __s = (void *)FUN_00408450(param_2,0x3414);
  if (__s != (void *)0x0) {
    memset(__s,0,param_2);
    memcpy(__s,param_1,param_2);
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      FUN_0051ad88(&local_28);
      local_48 = param_2;
      local_44 = __s;
      iVar2 = cw_parsed_pkt_create(7);
      if ((((iVar2 != 0) &&
           (iVar3 = cw_service_msg_add(iVar2,0x25,&local_30,1,0x42,&local_48), iVar3 != -1)) &&
          (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 != -1)) &&
         (iVar3 = serv_wtp_address_arg_init(&local_40), iVar3 != -1)) {
        apmngr_db_get_all_addr_by_capacity(&local_40,1,1,0x15f0000,1,7);
        uVar4 = serv_packet_send(&local_40,iVar1,1);
        FUN_00407df0(__s);
        cw_parsed_pkt_destroy(iVar2);
        cw_pkt_buf_destroy(iVar1);
        serv_wtp_address_arg_destroy(&local_40);
        return uVar4;
      }
    }
    FUN_00407df0(__s);
    if (iVar1 != 0) {
      cw_pkt_buf_destroy(iVar1);
    }
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    cw_parsed_pkt_destroy(iVar2);
  }
  return 0xffffffff;
}

