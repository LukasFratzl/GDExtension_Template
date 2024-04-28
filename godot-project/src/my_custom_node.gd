extends MyCustomNode


# Called when the node enters the scene tree for the first time.
func _ready():
	start_test();
	start_test_with_arguments("Hello from GD Extension with a string argument in gd script...");


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
