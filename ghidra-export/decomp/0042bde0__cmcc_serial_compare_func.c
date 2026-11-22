// func _cmcc_serial_compare_func @ 0042bde0 size=12

void _cmcc_serial_compare_func(void *param_1,int param_2)

{
  memcmp(param_1,(void *)(param_2 + 0x10),2);
  return;
}

