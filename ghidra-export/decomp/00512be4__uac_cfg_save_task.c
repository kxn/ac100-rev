// func _uac_cfg_save_task @ 00512be4 size=84

void _uac_cfg_save_task(void)

{
  int iVar1;
  int in_t9;
  
  iVar1 = *(int *)(in_t9 + 0x2467c8);
  do {
    do {
      (**(code **)(in_t9 + 0x246c04))(25000);
    } while (*(int *)(iVar1 + 0x1a70) == 0);
    _uac_cfg_chk_save();
  } while( true );
}

