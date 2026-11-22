// func capwap_network_session_init @ 00595e58 size=428

undefined4
capwap_network_session_init
          (void *param_1,int param_2,undefined4 param_3,void *param_4,void *param_5,int param_6,
          int param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  uVar1 = uVar3;
  if ((((param_1 != (void *)0x0) && (param_2 != -1)) && (uVar1 = 0xffffffff, param_4 != (void *)0x0)
      ) && (uVar1 = uVar3, param_5 != (void *)0x0)) {
    *(int *)((int)param_1 + 0x38) = param_2;
    memcpy(param_1,param_4,0x14);
    *(undefined2 *)((int)param_1 + 0x14) = *(undefined2 *)((int)param_4 + 0x14);
    uVar1 = *(undefined4 *)((int)param_4 + 0x18);
    *(undefined4 *)((int)param_1 + 0x54) = param_3;
    *(undefined4 *)((int)param_1 + 0x18) = uVar1;
    memcpy((void *)((int)param_1 + 0x1c),param_5,0x14);
    *(undefined2 *)((int)param_1 + 0x30) = *(undefined2 *)((int)param_5 + 0x14);
    *(undefined4 *)((int)param_1 + 0x34) = *(undefined4 *)((int)param_5 + 0x18);
    *(code **)((int)param_1 + 100) = capwap_packet_send;
    *(code **)((int)param_1 + 0x68) = capwap_packet_decrypt;
    *(code **)((int)param_1 + 0x6c) = capwap_network_free;
    *(code **)((int)param_1 + 0x70) = capwap_network_dump;
    FUN_0051ad88((int)param_1 + 0x58);
    uVar1 = 0;
    if ((param_6 != 0) && (uVar1 = 0xffffffff, param_7 != 0)) {
      *(int *)((int)param_1 + 0x4c) = param_7;
      iVar2 = capwap_dtls_data_create();
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d create dtls data failed\n","capwap_network_session_init",
                 0x16a);
        }
      }
      else {
        capwap_dtls_priv_data_init
                  (iVar2 + 4,param_7 + 0x104,param_2,param_4,param_5,(int)param_1 + 0x58);
        uVar1 = 0;
        capwap_dtls_data_init(iVar2,param_7,iVar2 + 4);
        *(int *)((int)param_1 + 0x50) = iVar2;
      }
    }
  }
  return uVar1;
}

