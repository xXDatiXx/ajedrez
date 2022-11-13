# ajedrez
Ajedrez con pila de movimientos, se puede regresar un movimiento, pero no se puede regresar un movimiento que se haya regresado


@import url('https://fonts.googleapis.com/css2?family=Righteous&display=swap');

$scene-width: 70vmin;
$scene-depth: 70vmin;
$scene-height: 10vmin;

$color-main: #5D7A8E;
$color-white: #E4C29244;
$color-black: #523F2144;
$color-chess-white: #B29671cc;
$color-chess-black: #404040cc;
$color-darken: 5%;

@mixin box($width, $height, $depth, $color) {
	width: $width;
  height: $height;
	
	.container {
    position: relative;
    width: 100%;
    height: 100%;
		
		* {
			position: absolute;
			bottom: 0;
			display: flex;
			justify-content: center;
			align-items: center; 
		}
		
		.left {
			width: $depth;
			height: $height;
			background-color: $color;
			transform-origin: left top;
			transform:
				rotateY(-90deg)
				translateX($depth / -2);
		}
		.right {
			width: $depth;
			height: $height;
			background-color: $color;
			transform-origin: left top;
			transform:
				rotateY(90deg)
				translateX($depth / -2)
				translateZ($width);
		}
		.top {
			background-color: lighten($color, 5%);
			width: $width;
			height: $depth;
			transform-origin: bottom left;
			transform:
				rotateX(90deg)
				translateY($depth / 2)
				translateZ($height);
		}
		.bottom {
			background-color: lighten($color, 5%);
			width: $width;
			height: $depth;
			transform-origin: bottom left;
			transform:
				rotateX(-90deg)
				translateY($depth / 2);
		}
		.front {
			background-color: darken($color, 10%);
			width: $width;
			height: $height;
			transform-origin: bottom left;
			transform:
				translateZ($depth / 2);
		}
		.back {
			background-color: darken($color, 10%);
			width: $width;
			height: $height;
			transform-origin: center;
			transform:
				rotateY(180deg)        
				translateZ($depth / 2)
        rotateX(180deg)
        rotateZ(180deg);
		}
	}
}
@mixin pawn($color) {
  width: 7vmin;
  height: 9vmin;
  .container {
    div:nth-child(1) {                      
      @include box(3vmin, 4vmin, 3vmin, $color);
      transform: translate3d(1vmin, 0vmin, 0vmin);
    }
    div:nth-child(2) {                      
      @include box(5vmin, 2vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, 0vmin, 0vmin);
    }
    div:nth-child(3) {                      
      @include box(5vmin, 1vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, -2.5vmin, 0vmin);
    }
    div:nth-child(4) {                      
      @include box(2vmin, 9vmin, 2vmin, $color);
      transform: translate3d(1.5vmin, 0vmin, 0vmin);
    }
    div:nth-child(5) {                      
      @include box(2vmin, 1.5vmin, 5vmin, $color);
      transform: translate3d(1.5vmin, -6vmin, 0vmin);
    }
    div:nth-child(6) {                      
      @include box(5vmin, 1.5vmin, 2vmin, $color);
      transform: translate3d(0vmin, -6vmin, 0vmin);
    }
  }
}
@mixin rook($color) {
  width: 7vmin;
  height: 12vmin;
  .container {
    div:nth-child(1) {                      
      @include box(3vmin, 9vmin, 3vmin, $color);
      transform: translate3d(1vmin, 0vmin, 0vmin);
    }
    div:nth-child(2) {                      
      @include box(5vmin, 2vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, 0vmin, 0vmin);
    }
    div:nth-child(3) {                      
      @include box(5vmin, 1vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, -2.5vmin, 0vmin);
    }
    div:nth-child(4) {                      
      @include box(5vmin, 1vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, -7vmin, 0vmin);
    }
    div:nth-child(5) {                      
      @include box(5vmin, 1vmin, 5vmin, $color);
      transform: translate3d(0vmin, -9vmin, 0vmin);
    }
    div:nth-child(6) {                      
      @include box(1vmin, 2vmin, 2vmin, $color);
      transform: translate3d(0vmin, -10vmin, -1.5vmin);
    }
    div:nth-child(7) {                      
      @include box(1vmin, 2vmin, 2vmin, $color);
      transform: translate3d(0vmin, -10vmin, 1.5vmin);
    }
    div:nth-child(8) {                      
      @include box(1vmin, 2vmin, 2vmin, $color);
      transform: translate3d(4vmin, -10vmin, -1.5vmin);
    }
    div:nth-child(9) {                      
      @include box(1vmin, 2vmin, 2vmin, $color);
      transform: translate3d(4vmin, -10vmin, 1.5vmin);
    }
    div:nth-child(10) {                      
      @include box(2vmin, 2vmin, 1vmin, $color);
      transform: 
        translate3d(0vmin, -10vmin, -2vmin);
    }
    div:nth-child(11) {                      
      @include box(2vmin, 2vmin, 1vmin, $color);
      transform: 
        translate3d(0vmin, -10vmin, 2vmin);
    }
    div:nth-child(12) {                      
      @include box(2vmin, 2vmin, 1vmin, $color);
      transform: 
        translate3d(3vmin, -10vmin, -2vmin);
    }
    div:nth-child(13) {                      
      @include box(2vmin, 2vmin, 1vmin, $color);
      transform: 
        translate3d(3vmin, -10vmin, 2vmin);
    }
  }
}
@mixin queen($color) {
  width: 7vmin;
  height: 19vmin;
  .container {
    div:nth-child(1) {                      
      @include box(3vmin, 18vmin, 3vmin, $color);
      transform: translate3d(1vmin, 0vmin, 0vmin);
    }
    div:nth-child(2) {                      
      @include box(5vmin, 5vmin, 5vmin, $color);
      transform: translate3d(0vmin, 0vmin, 0vmin);
    }
    div:nth-child(3) {                      
      @include box(6vmin, 2vmin, 6vmin, darken($color, $color-darken));
      transform: translate3d(-0.5vmin, 0vmin, 0vmin);
    }
    div:nth-child(4) {                      
      @include box(6vmin, 1vmin, 6vmin, darken($color, $color-darken));
      transform: translate3d(-0.5vmin, -2.5vmin, 0vmin);
    }
    div:nth-child(5) {                      
      @include box(4vmin, 2vmin, 4vmin, $color);
      transform: translate3d(0.5vmin, -13vmin, 0vmin);
    }
    div:nth-child(6) {                      
      @include box(4vmin, 1vmin, 4vmin, darken($color, $color-darken));
      transform: translate3d(0.5vmin, -16vmin, 0vmin);
    }
    div:nth-child(7) {                      
      @include box(1vmin, 1vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -18vmin, 0vmin);
    }
    div:nth-child(8) {                      
      @include box(1vmin, 1vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -16.5vmin, 0vmin);
    }
    div:nth-child(9) {                      
      @include box(5vmin, 1vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, -16.5vmin, 0vmin);
    }
    div:nth-child(10) {                      
      @include box(1vmin, 1vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, -16.5vmin, 1.75vmin);
    }
    div:nth-child(11) {                      
      @include box(1vmin, 1vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, -16.5vmin, -1.75vmin);
    }
    div:nth-child(12) {                      
      @include box(1vmin, 1vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(4vmin, -16.5vmin, 1.75vmin);
    }
    div:nth-child(13) {                      
      @include box(1vmin, 1vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(4vmin, -16.5vmin, -1.75vmin);
    }
  }
}
@mixin king($color) {
  width: 7vmin;
  height: 23vmin;
  .container {
    div:nth-child(1) {                      
      @include box(3vmin, 20vmin, 3vmin, $color);
      transform: translate3d(1vmin, 0vmin, 0vmin);
    }
    div:nth-child(2) {                      
      @include box(5vmin, 5vmin, 5vmin, $color);
      transform: translate3d(0vmin, 0vmin, 0vmin);
    }
    div:nth-child(3) {                      
      @include box(6vmin, 2vmin, 6vmin, darken($color, $color-darken));
      transform: translate3d(-0.5vmin, 0vmin, 0vmin);
    }
    div:nth-child(4) {                      
      @include box(6vmin, 1vmin, 6vmin, darken($color, $color-darken));
      transform: translate3d(-0.5vmin, -2.5vmin, 0vmin);
    }
    div:nth-child(5) {                      
      @include box(4vmin, 2vmin, 4vmin, $color);
      transform: translate3d(0.5vmin, -13vmin, 0vmin);
    }
    div:nth-child(6) {                      
      @include box(4vmin, 1vmin, 4vmin, darken($color, $color-darken));
      transform: translate3d(0.5vmin, -15.5vmin, 0vmin);
    }
    div:nth-child(7) {                      
      @include box(4vmin, 2vmin, 4vmin, $color);
      transform: translate3d(0.5vmin, -17vmin, 0vmin);
    }
    div:nth-child(8) {                      
      @include box(1vmin, 4vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -19vmin, 0vmin);
    }
    div:nth-child(9) {                      
      @include box(3vmin, 1vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(1vmin, -21vmin, 0vmin);
    }
  }
}
@mixin knight($color) {
  width: 7vmin;
  height: 14.5vmin;
  .container {
    div:nth-child(1) {                      
      @include box(3vmin, 4.5vmin, 3vmin, $color);
      transform: translate3d(1vmin, 0vmin, 0vmin);
    }
    div:nth-child(2) {                      
      @include box(5vmin, 2vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, 0vmin, 0vmin);
    }
    div:nth-child(3) {                      
      @include box(5vmin, 1vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, -2.5vmin, 0vmin);
    }
    div:nth-child(4) {                      
      @include box(3vmin, 1vmin, 4vmin, $color);
      transform: translate3d(1vmin, -4.5vmin, -0.5vmin);
    }
    div:nth-child(5) {                      
      @include box(3vmin, 2vmin, 5vmin, $color);
      transform: translate3d(1vmin, -5.5vmin, -1vmin);
    }
    div:nth-child(6) {                      
      @include box(3vmin, 1vmin, 4vmin, $color);
      transform: translate3d(1vmin, -7.5vmin, -0.5vmin);
    }
    div:nth-child(7) {                      
      @include box(3vmin, 4vmin, 3vmin, $color);
      transform: translate3d(1vmin, -8.5vmin, 0vmin);
    }
    div:nth-child(8) {                      
      @include box(3vmin, 1vmin, 5vmin, $color);
      transform: translate3d(1vmin, -9.5vmin, -1vmin);
    }
    div:nth-child(9) {                      
      @include box(3vmin, 1vmin, 4vmin, $color);
      transform: translate3d(1vmin, -11.5vmin, -0.5vmin);
    }
    div:nth-child(10) {                      
      @include box(3vmin, 1vmin, 1.5vmin, $color);
      transform: translate3d(1vmin, -10.5vmin, -2.75vmin);
    }
    div:nth-child(11) {                      
      @include box(1vmin, 1vmin, 5vmin, $color);
      transform: translate3d(2vmin, -12.5vmin, 0vmin);
    }
    div:nth-child(12) {                      
      @include box(1vmin, 8vmin, 1vmin, $color);
      transform: translate3d(2vmin, -5.5vmin, 2vmin);
    }
    div:nth-child(13) {                      
      @include box(1vmin, 1vmin, 0.75vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -13.5vmin, -1.75vmin);
    }
    div:nth-child(14) {                      
      @include box(1vmin, 1vmin, 0.75vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -13.5vmin, 0vmin);
    }
    div:nth-child(15) {                      
      @include box(1vmin, 1vmin, 0.75vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -13.5vmin, 1.75vmin);
    }    
    div:nth-child(16) {                      
      @include box(1vmin, 0.75vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -12vmin, 3vmin);
    }
    div:nth-child(17) {                      
      @include box(1vmin, 0.75vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -10.5vmin, 3vmin);
    }
    div:nth-child(18) {                      
      @include box(1vmin, 0.75vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -9vmin, 3vmin);
    }
    div:nth-child(19) {                      
      @include box(1vmin, 0.75vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -7.5vmin, 3vmin);
    }
    div:nth-child(20) {                      
      @include box(1vmin, 0.75vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -6vmin, 3vmin);
    }
  }
}
@mixin bishop($color) {
  width: 7vmin;
  height: 17vmin;
  .container {
    div:nth-child(1) {                      
      @include box(3vmin, 13vmin, 3vmin, $color);
      transform: translate3d(1vmin, 0vmin, 0vmin);
    }
    div:nth-child(2) {                      
      @include box(5vmin, 2vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, 0vmin, 0vmin);
    }
    div:nth-child(3) {                      
      @include box(5vmin, 1vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, -2.5vmin, 0vmin);
    }
    div:nth-child(4) {                      
      @include box(5vmin, 1vmin, 5vmin, darken($color, $color-darken));
      transform: translate3d(0vmin, -8vmin, 0vmin);
    }
    div:nth-child(5) {                      
      @include box(5vmin, 2vmin, 3vmin, $color);
      transform: translate3d(0vmin, -13vmin, 0vmin);
    }
    div:nth-child(6) {                      
      @include box(3vmin, 2vmin, 5vmin, $color);
      transform: translate3d(1vmin, -13vmin, 0vmin);
    }
    div:nth-child(7) {                      
      @include box(3vmin, 1vmin, 3vmin, $color);
      transform: translate3d(1vmin, -15vmin, 0vmin);
    }
    div:nth-child(8) {                      
      @include box(1vmin, 1vmin, 1vmin, darken($color, $color-darken));
      transform: translate3d(2vmin, -16vmin, 0vmin);
    }
  }
}

* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

body {
  display: grid;
  place-items: center;
  min-height: 100vh;
  background: $color-main;
  overflow: hidden;
  perspective: 1000px;
  
  .heading {
    position: absolute;
    top: 0;
    left: 0;
    right: 0;
    display: grid;
    place-items: center;
    text-align: center;
    padding: 2vmin;
    font-family: 'Righteous', cursive;
    color: $color-chess-black;
    font-size: clamp(0.9em, 1.5vmin, 1.1em);
    h1 {
      font-size: clamp(2em, 5vmin, 3em);      
    }
  }
  
  .scene, .scene * {
    transform-style: preserve-3d;
  }
  
  .scene {
    position: relative;
    width: $scene-width;
    height: $scene-height;
    transform:
      rotateX(0deg)
      rotateY(70deg)
      scale3d(1, 1, 1);
    animation: rot 40s ease-in-out 0s infinite alternate;	
		@keyframes rot {
      0% {
        transform: 
          rotateX(0deg)
          rotateY(70deg)
          scale3d(1, 1, 1);
      }
      50% {
        transform: 
          rotateX(-50deg)
          rotateY(440deg)
          scale3d(1, 1, 1);
      }
      100% {
        transform: 
          rotateX(-20deg)
          rotateY(880deg)
          scale3d(2, 2, 2);
      }
    }
    
    .cube, .cube *, .chess, .chess * {
			position: absolute;
			bottom: 0;
    }
    
    #ground {
      z-index: -50;
      $width: $scene-width;
      $height: 3vmin;
      $depth: $scene-depth;
      $color: $color-black;
      @include box($width, $height, $depth, $color);
      transform: translateY(3vmin);
      .container {
        .left, .right, .front, .back {
          background-image: 
            linear-gradient(180deg, #0000 0% 20%, darken($color-white, 10%) 20% 45%, #0000 45% 100%);
        }
        .bottom {
          background-color: #333;
          filter: drop-shadow(0 0 3.75rem black);
        }
        .top {
          box-shadow: 
            inset 0 0 15vmin #000a;
          &::after {
            content: '';
            position: absolute;
            width: 64vmin;
            height: 64vmin;
            $block-size: 16vmin;
            transform: translateY(-0.1vmin);
            box-shadow: 
              0 0 0 0.2vmin $color-white,
              0 0 0 0.4vmin $color-black,
              0 0 0 0.6vmin $color-white;
            background:
              repeating-conic-gradient($color-black 0% 25%, $color-white 0% 50%) 
                50% / #{$block-size $block-size};
            background-size: $block-size $block-size;
          }
          
        }
      }
    }

    .chess {
      position: absolute;
			width: 70vmin;
			height: 70vmin;
			bottom: 0;
      transform-origin: 35vmin 35vmin;
      transform: translate3d(0vmin, 0vmin, 0vmin);

      ._face {
        position: absolute;
        width: 100%;
        height: 100%;
        bottom: 0;
      }

      .white {
        width: 70vmin;
        height: 70vmin;
        transform: translateX(3.5vmin);
        
        #rook-white-1 {
          @include rook($color-chess-white);
          transform: translate3d(0vmin, 0vmin, 28vmin);
        }
        #rook-white-2 {
          @include rook($color-chess-white);
          transform: translate3d(56vmin, 0vmin, 28vmin);
        }
        #queen-white {
          @include queen($color-chess-white);
          transform: translate3d(24vmin, 0vmin, 28vmin);
          animation: move-queen-white 25s ease-in-out 2s infinite;
          @keyframes move-queen-white {
            0%, 48% {
              transform: translate3d(24vmin, 0vmin, 28vmin);
            }
            52% {
              transform: translate3d(24vmin, -20vmin, 28vmin);
            }
            56% {
              transform: translate3d(56vmin, -20vmin, -4vmin);
            }
            60%, 72% {
              transform: translate3d(56vmin, 0vmin, -4vmin);
            }
            76% {
              transform: translate3d(56vmin, -10vmin, -4vmin);
            }
            80% {
              transform: translate3d(40vmin, -10vmin, -20vmin);
            }
            84%, 100% {
              transform: translate3d(40vmin, 0vmin, -20vmin);
            }
          }
        }
        #king-white {
          @include king($color-chess-white);
          transform: translate3d(32vmin, 0vmin, 28vmin);
        }
        #knight-white-1 {
          @include knight($color-chess-white);
          transform: translate3d(8vmin, 0vmin, 28vmin);
        }
        #knight-white-2 {
          @include knight($color-chess-white);
          transform: translate3d(48vmin, 0vmin, 28vmin);
        }
        #bishop-white-1 {
          @include bishop($color-chess-white);
          transform: translate3d(16vmin, 0vmin, 28vmin);
        }
        #bishop-white-2 {
          @include bishop($color-chess-white);
          transform: translate3d(40vmin, 0vmin, 28vmin);
          animation: move-bishop-white-2 25s ease-in-out 2s infinite;
          @keyframes move-bishop-white-2 {
            0%, 24% {
              transform: translate3d(40vmin, 0vmin, 28vmin);
            }
            28% {
              transform: translate3d(40vmin, -20vmin, 28vmin);
            }
            32% {
              transform: translate3d(16vmin, -20vmin, 4vmin);
            }
            36%, 100% {
              transform: translate3d(16vmin, 0vmin, 4vmin);
            }
          }
        }
        
        @for $i from 1 through 8 {
          #pawn-white-#{$i} {
            @include pawn($color-chess-white);
            transform: translate3d(#{($i - 1) * 8}vmin, 0vmin, 20vmin);
          }
        }
        
        #pawn-white-5 {
          animation: move-pawn-white-5 25s ease-in-out 2s infinite;
          @keyframes move-pawn-white-5 {
            0% {
              transform: translate3d(32vmin, 0vmin, 20vmin);
            }
            4% {
              transform: translate3d(32vmin, -10vmin, 20vmin);
            }
            8% {
              transform: translate3d(32vmin, -10vmin, 4vmin);
            }
            12%, 100% {
              transform: translate3d(32vmin, 0vmin, 4vmin);
            }
          }
        }
      }
      
      .black {
        width: 70vmin;
        height: 70vmin;
        transform-origin: 35vmin 35vmin;
        transform: 
          translateX(-3.5vmin)
          rotateY(180deg);
        
        #rook-black-1 {
          @include rook($color-chess-black);
          transform: translate3d(0vmin, 0vmin, 28vmin);
        }
        #rook-black-2 {
          @include rook($color-chess-black);
          transform: translate3d(56vmin, 0vmin, 28vmin);
        }        
        #queen-black {
          @include queen($color-chess-black);
          transform: translate3d(32vmin, 0vmin, 28vmin);
        }
        #king-black {
          @include king($color-chess-black);
          transform-origin: center bottom -2.5vmin;
          transform: translate3d(24vmin, 0vmin, 28vmin);
          animation: move-king-black 25s ease-in-out 2s infinite;
          @keyframes move-king-black {
            0%, 84% {
              transform: translate3d(24vmin, 0vmin, 28vmin);
            }
            88%, 100% {
              transform: 
                translate3d(24vmin, 0vmin, 34vmin)
                rotateX(90deg);
            }
          }
        }
        #knight-black-1 {
          @include knight($color-chess-black);
          transform: translate3d(8vmin, 0vmin, 28vmin);
          animation: move-knight-black-1 25s ease-in-out 2s infinite;
          @keyframes move-knight-black-1 {
            0%, 60% {
              transform: translate3d(8vmin, 0vmin, 28vmin);
            }
            64% {
              transform: translate3d(8vmin, -20vmin, 28vmin);
            }
            68% {
              transform: translate3d(16vmin, -20vmin, 12vmin);
            }
            72%, 100% {
              transform: translate3d(16vmin, 0vmin, 12vmin);
            }
          }
        }
        #knight-black-2 {
          @include knight($color-chess-black);
          transform: translate3d(48vmin, 0vmin, 28vmin);
          animation: move-knight-black-2 25s ease-in-out 2s infinite;
          @keyframes move-knight-black-2 {
            0%, 36% {
              transform: translate3d(48vmin, 0vmin, 28vmin);
            }
            40% {
              transform: translate3d(48vmin, -20vmin, 28vmin);
            }
            44% {
              transform: translate3d(40vmin, -20vmin, 12vmin);
            }
            48%, 100% {
              transform: translate3d(40vmin, 0vmin, 12vmin);
            }
          }
        }
        #bishop-black-1 {
          @include bishop($color-chess-black);
          transform: translate3d(16vmin, 0vmin, 28vmin);
        }
        #bishop-black-2 {
          @include bishop($color-chess-black);
          transform: translate3d(40vmin, 0vmin, 28vmin);
        }
        
        @for $i from 1 through 8 {
          #pawn-black-#{$i} {
            @include pawn($color-chess-black);
            transform: translate3d(#{($i - 1) * 8}vmin, 0vmin, 20vmin);
          }
        }
        
        #pawn-black-4 {
          animation: move-pawn-black-4 25s ease-in-out 2s infinite;
          @keyframes move-pawn-black-4 {
            0%, 12% {
              transform: translate3d(24vmin, 0vmin, 20vmin);
            }
            16% {
              transform: translate3d(24vmin, -10vmin, 20vmin);
            }
            20% {
              transform: translate3d(24vmin, -10vmin, 4vmin);
            }
            24%, 100% {
              transform: translate3d(24vmin, 0vmin, 4vmin);
            }
          }
        }
        #pawn-black-3 {
          animation: move-pawn-black-3 25s ease-in-out 2s infinite;
          @keyframes move-pawn-black-3 {
            0%, 80%, 100% {
              visibility: visible;
            }
            80%, 99% {
              visibility: hidden;
            }
          }
        }
      }
    }
  }
}

mixin cube(id)
  div(id=id,class='cube')
    .container
      .left
      .right
      .top
      .bottom
      .front
      .back

mixin pawn(id)
  div(id=id,class='pawn')
    .container
      - for (i = 1; i <= 9; i++)
        +cube(id+'-'+i)
        
mixin rook(id)
  div(id=id,class='rook')
    .container
      - for (i = 1; i <= 13; i++)
        +cube(id+'-'+i)

mixin queen(id)
  div(id=id,class='queen')
    .container
      - for (i = 1; i <= 13; i++)
        +cube(id+'-'+i)

mixin king(id)
  div(id=id,class='king')
    .container
      - for (i = 1; i <= 9; i++)
        +cube(id+'-'+i)
        
mixin bishop(id)
  div(id=id,class='bishop')
    .container
      - for (i = 1; i <= 8; i++)
        +cube(id+'-'+i)

mixin knight(id)
  div(id=id,class='knight')
    .container
      - for (i = 1; i <= 20; i++)
        +cube(id+'-'+i)

.heading
  h1 Scholar's Mate
  p Scholar's Mate is usually one of the first checkmates that players learn or experience. The concept is simple: White targets the f7-square with both their queen and bishop early, in hopes of delivering checkmate in four moves.
.scene
  +cube('ground')
  .chess
    .white._face
      - for (n = 1; n <= 8; n++)
        +pawn('pawn-white-'+n)
      - for (n = 1; n <= 2; n++)
        +rook('rook-white-'+n)
      - for (n = 1; n <= 2; n++)
        +bishop('bishop-white-'+n)
      - for (n = 1; n <= 2; n++)
        +knight('knight-white-'+n)
      +queen('queen-white')
      +king('king-white')
    .black._face
      - for (n = 1; n <= 8; n++)
        +pawn('pawn-black-'+n)
      - for (n = 1; n <= 2; n++)
        +rook('rook-black-'+n)
      - for (n = 1; n <= 2; n++)
        +bishop('bishop-black-'+n)
      - for (n = 1; n <= 2; n++)
        +knight('knight-black-'+n)
      +queen('queen-black')
      +king('king-black')
