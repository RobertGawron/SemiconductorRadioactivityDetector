library(latticeExtra)
require(gridExtra)
require(grid)

# set error messages test to english
Sys.setenv(LANG = "en")

#load samples
samples <- read.delim("data.log", , sep=",")

# date column should be type of date, not string, so parse it
png(filename = paste0("results-", format(Sys.time(), "%d_%b_%Y_%H_%M"), ".png"), width = 800, height = 900, bg = "white")

# create graphs

samples$Time = as.POSIXct(samples$Time, format="%Y-%m-%d %H:%M:%S.%OS")

# create graphs
plotValueVsTime <- xyplot(Counter ~ Time, 
                data = samples, 
                type = "l", 
                grid = TRUE, 
                col.line = "black",
                ylab = "counts per minute",
		ylim=c(min(samples$Counter), max(samples$Counter)),

                xlim=c(min(samples$Time), max(samples$Time)),
                main = "Change over time")

plotHistogram <- histogram(samples$Counter, 
                           color = "white", 
                           col = "grey", 
                           xlab = "counts", 
                           ylab = "percentage", 
                           main = "Histogram")

# show graphs
grid.arrange(plotValueVsTime, plotHistogram, nrow = 2)

# add timestamp
trellis.focus("toplevel")
pictureCreationTimestamp <- as.POSIXlt(Sys.time())
panel.text(0.85, 0.03, pictureCreationTimestamp, cex = 1.2, font = 2)
trellis.unfocus()
