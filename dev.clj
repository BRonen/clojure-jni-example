(ns dev
  (:import [Accumulator Acc]
           [Callbacks Callbacks]))

(def acc (Acc.))

(comment
  (.accumulate acc 1)
  (.getValue acc)

  nil)

(def callbacks (Callbacks.))

(comment
  (.apply_callback callbacks 2 (fn [x] (* x 5)))

  (.apply_bicallback callbacks 3 2 (fn [x y] (* x y)))

  nil)
