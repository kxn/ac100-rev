// func uac_lldp_pkt_uninit @ 004a448c size=112

undefined4 uac_lldp_pkt_uninit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = serv_msg_mngr_unregister(9,0x78,_uac_lldp_pkt_echo_req_listen);
  if ((iVar1 == -1) && (uVar2 = 0xffffffff, uac_lldp_err_switch != '\0')) {
    printf("[UAC_LLDP_ERROR]%s()/%d unregister callback to listen join-req capwap message event failed.\n"
           ,"uac_lldp_pkt_uninit",0x216);
  }
  return uVar2;
}

