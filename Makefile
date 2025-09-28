
LIBS = -lraylib -lwinmm -lgdi32

meter-sim.exe: main.o
	$(CXX) -o $@ $^

clean:
	rm -rf *.o meter-sim.exe

main.o: src/main.cpp sim_controller.o
	$(CXX) -c $^

sim_controller.o: src/sim_controller.cpp water_meter.o
	$(CXX) -c $^

water_meter.o: src/water_meter.cpp meter.o my_window.o
	$(CXX) -c $^

meter.o: src/meter.cpp pipe.o
	$(CXX) -c $^

pipe.o: src/pipe.cpp
	$(CXX) -c $^

my_window.o: src/my_window.cpp
	$(CXX) -c $^ $(LIBS)
