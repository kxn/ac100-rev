// func _uac_print_mutex @ 00522c60 size=76

undefined4 _uac_print_mutex(int param_1)

{
  printf("Mutex \"%s\": type=%d, owner=%p, lock_cnt=%lu\n",*(undefined4 *)(param_1 + 0x18),
         *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),
         *(undefined4 *)(param_1 + 0x24));
  return 0;
}

