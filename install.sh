ROOT_DIR=`pwd`
if [ -d "$ROOT_DIR/build" ]; then
   echo "deleting build"
   rm -r build  
fi
   mkdir -p build && cd build && \
   cmake ../
   make



