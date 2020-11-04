CMAKE_COMMON = cmake -DUSE_CCACHE=YES -DCMAKE_TOOLCHAIN_FILE=$(CMAKE_VCPKG_TOOLCHAINS)
nproc = $(shell expr $(shell nproc) + 1)

.PHONY: all run.debug run.release test pack clean ninja.debug ninja.release

run.debug:
	cmake --build build/Debug -j $(nproc)

run.release:
	cmake --build build/Release -j $(nproc)

test: ninja.debug
	cmake --build build/Debug -j $(nproc)
	./build/Debug/out/bin/lcrypt-test
	./build/Debug/out/bin/lcrypt-bench

clangd: ninja.debug
	cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -Bbuild/Debug
	mv build/Debug/compile_commands.json .

ninja.debug:
	$(CMAKE_COMMON) -G Ninja -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug -Bbuild/Debug

ninja.release:
	$(CMAKE_COMMON) -G Ninja -DBUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release -Bbuild/Release

msvc:
	$(CMAKE_COMMON) -DBUILD_TESTS=ON -Bbuild/msvc

clean:
	rm -rf build
