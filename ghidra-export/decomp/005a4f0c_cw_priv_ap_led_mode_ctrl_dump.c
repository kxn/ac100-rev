// func cw_priv_ap_led_mode_ctrl_dump @ 005a4f0c size=132

undefined4 cw_priv_ap_led_mode_ctrl_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap led mode control \r\n",(uint)*(ushort *)(param_1 + 0xc)
         ,(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap led mode control (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x \r\n",*puVar1);
  printf("\t\t\t\tap led mode control: %d \r\n ",*puVar1);
  return 0;
}

