// func _wportal_flush_free_all @ 00412a28 size=32

void _wportal_flush_free_all(void)

{
  _wportal_free_flush_handle(0);
  _wportal_free_flush_handle(1);
  return;
}

