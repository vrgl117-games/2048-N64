FROM vieux/libdragon:conker64

RUN apt-get update && apt-get install -yq sox imagemagick

COPY . /2048-N64
WORKDIR /2048-N64

RUN mkdir -p filesystem/gfx/sprites filesystem/gfx/maps
RUN make